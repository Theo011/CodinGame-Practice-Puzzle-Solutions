#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

int main()
{
    std::vector<std::map<std::string, std::string>> instructions =
    {
        {{"", ""}},
        {{"TOP", "DOWN"}, {"LEFT", "DOWN"}, {"RIGHT", "DOWN"}},
        {{"LEFT", "RIGHT"}, {"RIGHT", "LEFT"}},
        {{"TOP","DOWN"}},
        {{"TOP", "LEFT"}, {"RIGHT", "DOWN"}},
        {{"TOP", "RIGHT"}, {"LEFT", "DOWN"}},
        {{"LEFT", "RIGHT"}, {"RIGHT", "LEFT"}},
        {{"TOP", "DOWN"}, {"RIGHT", "DOWN"}},
        {{"LEFT", "DOWN"}, {"RIGHT", "DOWN"}},
        {{"TOP", "DOWN"}, {"LEFT", "DOWN"}},
        {{"TOP", "LEFT"}},
        {{"TOP", "RIGHT"}},
        {{"RIGHT", "DOWN"}},
        {{"LEFT", "DOWN"}},
    };

    int w, h;

    std::cin >> w >> h; std::cin.ignore();

    std::vector<std::vector<int>> gameMap(h, std::vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        std::string line, tempString;
        int j = 0;

        getline(std::cin, line);

        std::istringstream tempInput(line);

        while (getline(tempInput, tempString, ' '))
        {
            gameMap[i][j] = std::stoi(tempString);
            j++;
        }
    }

    int ex;

    std::cin >> ex; std::cin.ignore();

    while (1)
    {
        int xi, yi;
        std::string pos;

        std::cin >> xi >> yi >> pos; std::cin.ignore();

        if (instructions[gameMap[yi][xi]][pos].compare("DOWN") == 0)
        {
            yi++;
            std::cout << xi << " " << yi << std::endl;
            continue;
        }

        if (instructions[gameMap[yi][xi]][pos].compare("LEFT") == 0)
        {
            xi--;
            std::cout << xi << " " << yi << std::endl;
            continue;
        }

        if (instructions[gameMap[yi][xi]][pos].compare("RIGHT") == 0)
        {
            xi++;
            std::cout << xi << " " << yi << std::endl;
            continue;
        }
    }
}