#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

std::string Hash(std::string input)
{
    std::stringstream hex_hash;

    // Starting primes
    unsigned int hex_arr[8] = {0xe49b69c1, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x14292967};
    // Other primes for calculations
    const int primes[30] = {107, 5, 229, 23, 3, 73, 7, 113, 181, 131, 47, 139, 79, 241, 89, 257, 23, 101, 269, 151, 163, 173, 193, 59, 199, 211, 223, 277, 239, 307};
    for (size_t i = 0; i < input.length(); i++)
    {
        double ascii = (int)input[i];
        // Handling "negative" ascii values
        if (ascii < 0)
        {
            ascii += 256;
        }

        unsigned int x = (double)(primes[(unsigned int)(ascii + i) % 30]) / double(307 + ascii / 2) * pow(2, 32); // formula

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