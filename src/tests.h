#include <random>
#include <string>
#include <time.h>

std::string CollisionTest(std::string (*hash_func)(std::string), int symbol_count)
{
    srand(time(NULL));
    int collision_count = 0;
    const std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=[];',./\\_+{}:\">?|`~";
    for (int i = 0; i < 25000; i++)
    {
        std::string s1 = "", s2 = "";
        for (int j = 0; j < symbol_count; j++)
        {

            s1 += symbols[rand() % symbols.length()];
            s2 += symbols[rand() % symbols.length()];
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
    const std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=[];',./\\_+{}:\">?|`~";
    for (int i = 0; i < 25000; i++)
    {
        std::string s1 = "", s2 = "";
        for (int j = 0; j < symbol_count; j++)
        {

            s1 += symbols[rand() % symbols.length()];
            s2 += s1;
        }
        s1[rand() % symbol_count] = symbols[rand() % symbols.length()];
        if (s1 != s2)
        {
            int hex_diff = 0, bit_diff = 0;
            for (int j = 0; j < 64; j++)
            {
                if (s1[j] != s2[j])
                {
                    hex_diff++;
                }
            }
            if (hex_diff < diffs[0])
                diffs[0] = hex_diff;
            if (hex_diff > diffs[2])
                diffs[2] = hex_diff;
            diffs[4] += hex_diff;
            // for (int j = 0; j < 256; j++)
            // {
            // }
        }
    }
}