#include "myhash.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

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
    buffer.clear();
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
        std::cout << "Enter your input:" << std::endl;
        std::getline(std::cin, input);
    }

    output = Hash(input);
    std::cout << output << std::endl;
    std::cout << output.length() << std::endl;

    return 0;
}