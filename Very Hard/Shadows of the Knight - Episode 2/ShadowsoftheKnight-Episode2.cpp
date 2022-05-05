#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

// Based on https://ethiery.github.io/codingame/shadows-of-the-knight-2.html written in python.
// This is my take on Etienne's code but in c++.
// I'm sure it's unoptimized as hell but hey, it works.

struct Range
{
    std::vector<int> x_range, y_range;

    Range() = default;

    Range(const int& w, const int& h)
    {
        for (int i = 0; i < w; i++)
        {
            x_range.push_back(i);
        }

        for (int i = 0; i < h; i++)
        {
            y_range.push_back(i);
        }
    }
};

Range dichotomy(const int& x0, const int& y0, const int& x, const int& y, const Range& range, const std::string& bomb_dir, Range& temp_range)
{
    if (range.x_range.size() != 1)
    {
        temp_range.x_range.clear();

        if (bomb_dir.compare("UNKNOWN") == 0)
        {
            return range;
        }
        else if (bomb_dir.compare("SAME") == 0)
        {
            for (int i : range.x_range)
            {
                if (abs(x0 - i) == abs(x - i))
                {
                    temp_range.x_range.push_back(i);
                }
            }
        }
        else if (bomb_dir.compare("WARMER") == 0)
        {
            for (int i : range.x_range)
            {
                if (abs(x0 - i) > abs(x - i))
                {
                    temp_range.x_range.push_back(i);
                }
            }
        }
        else
        {
            for (int i : range.x_range)
            {
                if (abs(x0 - i) < abs(x - i))
                {
                    temp_range.x_range.push_back(i);
                }
            }
        }
    }
    else
    {
        temp_range.y_range.clear();

        if (bomb_dir.compare("UNKNOWN") == 0)
        {
            return range;
        }
        else if (bomb_dir.compare("SAME") == 0)
        {
            for (int i : range.y_range)
            {
                if (abs(y0 - i) == abs(y - i))
                {
                    temp_range.y_range.push_back(i);
                }
            }
        }
        else if (bomb_dir.compare("WARMER") == 0)
        {
            for (int i : range.y_range)
            {
                if (abs(y0 - i) > abs(y - i))
                {
                    temp_range.y_range.push_back(i);
                }
            }
        }
        else
        {
            for (int i : range.y_range)
            {
                if (abs(y0 - i) < abs(y - i))
                {
                    temp_range.y_range.push_back(i);
                }
            }
        }
    }

    return temp_range;
}

int main()
{
    int w, h, n, x0, y0;

    std::cin >> w >> h; std::cin.ignore();
    std::cin >> n; std::cin.ignore();
    std::cin >> x0 >> y0; std::cin.ignore();

    int x = x0, y = y0;
    Range range(w, h), temp_range;

    temp_range = range;

    while (1)
    {
        std::string bomb_dir;

        std::cin >> bomb_dir; std::cin.ignore();
        range = dichotomy(x0, y0, x, y, range, bomb_dir, temp_range);
        x0 = x;
        y0 = y;

        if (range.x_range.size() != 1)
        {
            if (x0 == 0 && range.x_range.size() != w)
            {
                x = (3 * range.x_range.front() + range.x_range.back()) / 2 - x0;
            }
            else if (x0 == w - 1 && range.x_range.size() != w)
            {
                x = (range.x_range.front() + 3 * range.x_range.back()) / 2 - x0;
            }
            else
            {
                x = range.x_range.front() + range.x_range.back() - x0;
            }

            if (x == x0)
            {
                x++;
            }

            x = std::min(std::max(x, 0), w - 1);
        }
        else
        {
            if (x != range.x_range.front())
            {
                x = x0 = range.x_range.front();
                std::cout << x << " " << y << std::endl;
                std::cin >> bomb_dir; std::cin.ignore();
            }
            
            if (range.y_range.size() == 1)
            {
                y = range.y_range.front();
            }
            else
            {
                if (y0 == 0 && range.y_range.size() != h)
                {
                    y = (3 * range.y_range.front() + range.y_range.back()) / 2 - y0;
                }
                else if (y0 == h - 1 && range.y_range.size() != h)
                {
                    y = (range.y_range.front() + 3 * range.y_range.back()) / 2 - y0;
                }
                else
                {
                    y = range.y_range.front() + range.y_range.back() - y0;
                }

                y = std::min(std::max(y, 0), h - 1);
            }
        }
        
        std::cout << x << " " << y << std::endl;
    }
}