#include <iostream>
#include <cmath>

int main()
{
    int n, closest = 0;

    std::cin >> n; std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        int t;

        std::cin >> t; std::cin.ignore();

        if (i == 0 || abs(t) < abs(closest))
            closest = t;
        else if (abs(t) == abs(closest) && t != closest)
            closest = abs(t);
    }

    std::cout << closest << std::endl;
}