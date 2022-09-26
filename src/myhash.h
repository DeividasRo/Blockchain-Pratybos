#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

std::string Hash(std::string input)
{
    std::stringstream hex_hash;

    unsigned int hex_arr[8] = {0xe49b69c1, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x14292967}; // Starting primes
    const int primes[10] = {43, 139, 251, 373, 491, 619, 757, 887, 1033, 1181};                                                 // Other primes for calculations
    for (size_t i = 0; i < input.length(); i++)
    {
        double ascii = (int)input[i];
        if (ascii < 0)
        {
            ascii += 256;
        }
        unsigned int x = ((ascii * primes[(int)ascii % 10]) / (input.length() + ascii * primes[i % 10]) * pow(2, 32)); // formula
        for (int j = 0; j < 8; j++)
        {
            unsigned int temp;
            // Bit manipulations:
            hex_arr[j] ^= x;
            temp = hex_arr[j];
            hex_arr[j] >>= 4;
            hex_arr[j] ^= temp;
        }
    }
    // Pushing hex values from array of hexes into the stringstream and adds leading zeroes where needed to preserve 8 symbol hexes
    for (int i = 0; i < 8; i++)
    {
        hex_hash << std::setfill('0') << std::setw(8) << std::right << std::hex << hex_arr[i];
    }

    // Returning stringstream value converted into string
    return hex_hash.str();
}