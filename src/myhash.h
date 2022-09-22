#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
std::string Hash(std::string input)
{
    std::stringstream hex_hash;
    unsigned const int min = 268435456;
    unsigned const int max = 4294967295;
    unsigned int hex_arr[8] = {0xe49b69c1, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x14292967};
    const int primes[10] = {43, 139, 251, 373, 491, 619, 757, 887, 1033, 1181};
    for (int i = 0; i < input.length(); i++)
    {
        unsigned int x = (((double)input[i] * primes[(int)input[i] % 10]) * 25163 / ((double)input.length() + (double)input[i] * primes[i % 10] * 27277) * pow(2, 32));
        for (int j = 0; j < 8; j++)
        {
            unsigned int temp;
            hex_arr[j] ^= x;
            temp = hex_arr[j];
            hex_arr[j] >>= 4;
            hex_arr[j] ^= temp;
            if (hex_arr[j] < min)
            {
                hex_arr[j] = max - (min - hex_arr[j]);
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        hex_hash << std::hex << hex_arr[i];
    }
    std::string output = hex_hash.str();
    return output;
}