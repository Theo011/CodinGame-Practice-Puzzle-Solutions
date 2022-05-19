#include <iostream>
#include <string>

int main()
{
    std::string message;

    getline(std::cin, message);

    bool first_bit = message[0] & 0x40; // 0x40 = 0100 0000 (8-bit) so 100 0000 (7-bit)

    std::cout << (first_bit ? "0 " : "00 ");

    for (auto c : message)
    {
        for (auto i = 0x40; i != 0; i >>= 1) // bit shift right (halves it)
        {
            bool bit = c & i;

            std::cout << ((bit == first_bit) ? "0" : (first_bit = bit) ? " 0 0" : " 00 0"); // if bit is equal to first_bit print 0 otherwise change first_bit to bit
        }
    }

    std::cout << std::endl;
}