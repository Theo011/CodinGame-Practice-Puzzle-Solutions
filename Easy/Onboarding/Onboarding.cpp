#include <iostream>

int main()
{
    while (1)
    {
        std::string enemy1, enemy2;
        int dist1, dist2;

        std::cin >> enemy1; std::cin.ignore();
        std::cin >> dist1; std::cin.ignore();
        std::cin >> enemy2; std::cin.ignore();
        std::cin >> dist2; std::cin.ignore();

        if (dist1 < dist2)
            std::cout << enemy1 << std::endl;
        else
            std::cout << enemy2 << std::endl;
    }
}