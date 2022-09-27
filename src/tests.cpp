#include "tests.h"
#include <iostream>
const std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=[];',./\\_+{}:\"<>?|`~";
std::uniform_int_distribution<int> dist(0, symbols.length());
std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

// Function to convert hex char to binary string
std::string HexCharToBin(char c)
{
    // TODO handle default / error
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

std::string CollisionTest(std::string (*hash_func)(std::string), int symbol_count)
{
    srand(time(NULL));
    int collision_count = 0;

    for (int i = 0; i < 25000; i++)
    {
        std::string s1 = "", s2 = "";
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

    return "Collisions detected: " + std::to_string(collision_count);
}

void AvalancheTest(std::string (*hash_func)(std::string), int symbol_count, int diffs[])
{
    srand(time(NULL));
    for (int i = 0; i < 25000; i++)
    {
        std::string s1 = "", s2 = "";

        for (int j = 0; j < symbol_count; j++)
        {
            s1 += symbols[dist(mt)];
        }

        s2 = s1;
        s1[rand() % symbol_count] = symbols[dist(mt)];

        if (s1 != s2)
        {
            int hex_diff = 0, bit_diff = 0;
            std::string h1 = hash_func(s1);
            std::string h2 = hash_func(s2);

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

            std::string b1, b2;
            for (int i = 0; i < 64; i++)
            {
                b1 = HexCharToBin(h1[i]);
                b2 = HexCharToBin(h1[i]);
            }

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