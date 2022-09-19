#include <iostream>

std::string hash(std::string input)
{
    std::string hex_str = "0x";
    for (int i = 0; i < 64; i++)
    {
    }
    return hex_str;
}

int main()
{
    std::string input = "Pratybos", output;
    output = hash(input);
    std::cout << output;
    return 0;
}