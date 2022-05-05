#include <iostream>

int main()
{
    int light_x, light_y, initial_tx, initial_ty;

    std::cin >> light_x >> light_y >> initial_tx >> initial_ty; std::cin.ignore();

    int distance_x = light_x - initial_tx, distance_y = light_y - initial_ty;

    while (1)
    {
        int remaining_turns;

        std::cin >> remaining_turns; std::cin.ignore();

        if (distance_y > 0)
        {
            distance_y--;
            std::cout << "S";
        }

        if (distance_y < 0)
        {
            distance_y++;
            std::cout << "N";
        }

        if (distance_x > 0)
        {
            distance_x--;
            std::cout << "E";
        }

        if (distance_x < 0)
        {
            distance_x++;
            std::cout << "W";
        }

        std::cout << std::endl;
    }
}