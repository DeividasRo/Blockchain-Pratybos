#include "tests.h"

const std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=[];',./\\_+{}:\"<>?|`~";

std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
std::uniform_int_distribution<int> dist(0, symbols.length());

// Function to convert hex char to binary string
std::string HexCharToBin(char c)
{
    switch (toupper(c))
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    }
    return "";
}

int CollisionTest(std::string (*hash_func)(std::string), int symbol_count)
{
    srand(time(NULL));
    int collision_count = 0;

    for (int i = 0; i < 25000; i++)
    {
        std::string s1 = "", s2 = "";
        // Generate two strings with random symbols
        for (int j = 0; j < symbol_count; j++)
        {
            s1 += symbols[dist(mt)];
            s2 += symbols[dist(mt)];
        }
        if (s1 != s2)
        {
            if (hash_func(s1) == hash_func(s2))
                collision_count++;
        }
    }

    return collision_count;
}

void AvalancheTest(std::string (*hash_func)(std::string), int symbol_count, int diffs[])
{
    srand(time(NULL));
    for (int i = 0; i < 25000; i++)
    {
        std::string s1 = "", s2 = "";
        // Generate one string with random symbols
        for (int j = 0; j < symbol_count; j++)
        {
            s1 += symbols[dist(mt)];
        }

        s2 = s1;                                       // Copy string1 value to string2
        s1[rand() % symbol_count] = symbols[dist(mt)]; // Change one random symbol of string2

        if (s1 != s2)
        {
            int hex_diff = 0;
            std::string h1 = hash_func(s1), h2 = hash_func(s2);

            // Checking each symbol for difference at j position of both strings
            for (int j = 0; j < 64; j++)
            {
                if (h1[j] != h2[j])
                {
                    hex_diff++;
                }
            }

            if (hex_diff < diffs[0])
                diffs[0] = hex_diff;
            if (hex_diff > diffs[2])
                diffs[2] = hex_diff;
            diffs[4] += hex_diff;

            int bit_diff = 0;
            std::string b1 = "", b2 = "";

            // Creating binary string from hex string
            for (int j = 0; j < 64; j++)
            {
                b1 += HexCharToBin(h1[j]);
                b2 += HexCharToBin(h2[j]);
            }

            // Checking each symbol for difference at j position of both strings
            for (int j = 0; j < 256; j++)
            {
                if (b1[j] != b2[j])
                {
                    bit_diff++;
                }
            }

            if (bit_diff < diffs[1])
                diffs[1] = bit_diff;
            if (bit_diff > diffs[3])
                diffs[3] = bit_diff;
            diffs[5] += bit_diff;
        }
    }
}