#include <iostream>

int main()
{
    while (1)
    {
        int highest = -1, highest_i;

        for (int i = 0; i < 8; i++)
        {
            int mountain_h;

            std::cin >> mountain_h; std::cin.ignore();
             
            if (mountain_h > highest)
            {
                highest = mountain_h;
                highest_i = i;
            }
        }

        std::cout << highest_i << std::endl;
    }
}