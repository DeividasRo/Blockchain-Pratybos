#include "myhash.h"
#include "tests.h"
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

    if (argc == 2) // One command line argument - text file name
    {
        if (argv[1] == std::string("coltest"))
        {
            std::cout << "1# Testing 25000 pairs of strings, each string consists of 10 random symbols..." << std::endl;
            std::cout << CollisionTest(&Hash, 10) << std::endl;
            std::cout << "2# Testing 25000 pairs of strings, each string consists of 100 random symbols..." << std::endl;
            std::cout << CollisionTest(&Hash, 100) << std::endl;
            std::cout << "3# Testing 25000 pairs of strings, each string consists of 500 random symbols..." << std::endl;
            std::cout << CollisionTest(&Hash, 500) << std::endl;
            std::cout << "4# Testing 25000 pairs of strings, each string consists of 1000 random symbols..." << std::endl;
            std::cout << CollisionTest(&Hash, 1000) << std::endl;
            return 0;
        }
        else
        {
            input = ReadFileToString(argv[1]);
        }
    }
    else if (argc == 3) // Two command line arguments - text file name and amount of lines to read
    {
        input = ReadFileToString(argv[1], std::stoi(argv[2]));
    }
    else // No command line arguments
    {
        std::cout << "Enter your input:" << std::endl;
        std::getline(std::cin, input);
    }

    auto start = std::chrono::high_resolution_clock::now();

    output = Hash(input);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << output << std::endl;
    std::cout << "Duration: " << duration.count() << " microseconds" << std::endl;

    return 0;
}