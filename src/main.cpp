#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

std::string Hash(std::string input)
{
    std::stringstream hex_str;
    int primes[8] = {3727,
                     6301,
                     5279,
                     7727,
                     1847,
                     719,
                     389,
                     16963}; // atsitiktiniai pirminiai skaiciai mazesni uz 65535
    int hex_parts[64];

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < 64; j++)
        {
            hex_parts[j] = (primes[j / 8] * (int)input[i]) ^ (hex_parts[j] * primes[j % 8]) % 16;
        }
        for (int j = 63; j >= 0; j--)
        {
            hex_parts[j] = (primes[j / 8] * (int)input[i]) ^ (hex_parts[j] * primes[j % 8]) % 16;
        }
    }
    for (int i = 0; i < 64; i++)
    {
        hex_str << std::hex << hex_parts[i];
    }
    std::string output = hex_str.str(); // paskutiniai 64 hex'o simboliai atrenkami kaip hash'as
    return output;
}

std::string ReadFileToString(std::string file_name)
{
    std::stringstream buffer;
    std::ifstream inf;
    inf.open("text-files/" + file_name);
    if (inf)
    {
        buffer << inf.rdbuf();
    }
    else
    {
        throw std::runtime_error(std::string("Failed to load file!"));
    }
    inf.close();
    return buffer.str();
}

int main(int argc, char *argv[])
{
    std::string input, output;

    if (argc > 1)
    {
        input = ReadFileToString(argv[1]);
    }
    else
    {
        std::string file_name;
        std::cout << "Enter the full name of the file that you want to read as input:" << std::endl;
        std::cin >> file_name;
        ReadFileToString(file_name);
    }

    output = Hash(input);
    std::cout << output << std::endl;
    std::cout << output.length() << std::endl;

    return 0;
}