#include "myhash.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <chrono>

std::string ReadFileToString(std::string file_name, int lines_to_read = 0)
{
    std::stringstream buffer;
    std::ifstream inf;
    inf.open("text-files/" + file_name);
    if (inf)
    {
        if (lines_to_read == 0)
            buffer << inf.rdbuf();
        else
        {
            std::string line;
            while (std::getline(inf, line) && lines_to_read != 0)
            {
                buffer << line;
                lines_to_read--;
            }
        }
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

    if (argc == 2)
    {
        input = ReadFileToString(argv[1]);
    }
    else if (argc == 3)
    {
        input = ReadFileToString(argv[1], std::stoi(argv[2]));
    }
    else
    {
        std::cout << "Enter your input:" << std::endl;
        std::getline(std::cin, input);
    }

    auto start = std::chrono::high_resolution_clock::now();

    output = Hash(input);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << output << std::endl;
    std::cout << "Duration: " << duration.count() << " ms" << std::endl;

    return 0;
}