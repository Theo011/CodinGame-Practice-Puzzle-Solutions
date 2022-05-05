#include <iostream>
#include <string>

int main()
{
    int w, h, n, x0, y0;

    std::cin >> w >> h; std::cin.ignore();
    std::cin >> n; std::cin.ignore();
    std::cin >> x0 >> y0; std::cin.ignore();

    int min_x = 0, min_y = 0, max_x = w--, max_y = h--;

    while (1)
    {
        std::string bomb_dir;

        std::cin >> bomb_dir; std::cin.ignore();

        if (bomb_dir.find('U') != std::string::npos)
            max_y = y0 - 1;

        if (bomb_dir.find('D') != std::string::npos)
            min_y = y0 + 1;
        
        if (bomb_dir.find('L') != std::string::npos)
            max_x = x0 - 1;

        if (bomb_dir.find('R') != std::string::npos)
            min_x = x0 + 1;

        y0 = min_y + (max_y - min_y) / 2;
        x0 = min_x + (max_x - min_x) / 2;
        std::cout << x0 << " " << y0 << std::endl;
    }
}