#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

std::string hash(std::string input)
{
    std::stringstream hex_str;
    int p1 = 30983, p2 = 9679, p3 = 2341; // atsitiktiniai pirminiai skaiciai
    unsigned int s = 71;
    for (int j = 0; j < 64; j++)
    {
        s = ((p1 * s + input.length()) ^ ((int)input[j % input.length()] * p2));
        hex_str << std::hex << s % p3;
    }

    return hex_str.str().substr(hex_str.str().length() - 64, 64); // paskutiniai 64 hex'o simboliai atrenkami kaip hash'as
}

int main()
{
    std::string input = "Pratybos, ir kita", output;
    output = hash(input);
    std::cout << output << std::endl;
    std::cout << output.length();

    return 0;
}