#include <iostream>

int main()
{
    int surface_n;
    
    std::cin >> surface_n; std::cin.ignore();

    for (int i = 0; i < surface_n; i++)
    {
        int land_x, land_y;

        std::cin >> land_x >> land_y; std::cin.ignore();
    }

    while (1)
    {
        int x, y, h_speed, v_speed, fuel, rotate, power;

        std::cin >> x >> y >> h_speed >> v_speed >> fuel >> rotate >> power; std::cin.ignore();

        if (v_speed <= -40)
            std::cout << "0 4" << std::endl;
        else
            std::cout << "0 0" << std::endl;
    }
}