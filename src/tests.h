#include <random>
#include <string>
#include <time.h>

std::string CollisionTest(std::string (*hash_func)(std::string), int symbol_count)
{
    srand(time(NULL));
    int collision_count = 0;
    const std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
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