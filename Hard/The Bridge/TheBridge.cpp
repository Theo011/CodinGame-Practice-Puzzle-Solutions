#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string> map(4);
size_t last_hole = 0;

struct State
{
    std::vector<int> y;
    int speed, x;
};

std::pair<int, std::string> decide(const State& state)
{
    if (state.x >= last_hole)
        return { 0, "WAIT" };

    if (state.speed == 0)
        return { 0, "SPEED" };

    std::pair<int, std::string> min_casualties = { state.y.size(), "WAIT" };

    {
        State new_state = state;

        ++new_state.speed;
        new_state.x += new_state.speed;

        for (auto y : state.y)
        {
            for (int x = state.x + 1; x <= new_state.x; ++x)
            {
                if (map[y][x] == '0')
                {
                    new_state.y.erase(std::find(new_state.y.begin(), new_state.y.end(), y));

                    break;
                }
            }
        }

        if (new_state.y.size() > 0)
        {
            int casualties = (state.y.size() - new_state.y.size()) + decide(new_state).first;

            if (casualties == 0)
                return { 0, "SPEED" };

            if (casualties < min_casualties.first)
                min_casualties = { casualties, "SPEED" };
        }
    }

    {
        State new_state = state;

        new_state.x += new_state.speed;

        for (auto y : state.y)
        {
            for (int x = state.x + 1; x <= new_state.x; ++x)
            {
                if (map[y][x] == '0')
                {
                    new_state.y.erase(std::find(new_state.y.begin(), new_state.y.end(), y));

                    break;
                }
            }
        }

        if (new_state.y.size() > 0)
        {
            int casualties = (state.y.size() - new_state.y.size()) + decide(new_state).first;

            if (casualties == 0)
                return { 0, "WAIT" };

            if (casualties < min_casualties.first)
                min_casualties = { casualties, "WAIT" };
        }
    }

    {
        State new_state = state;
        
        new_state.x += new_state.speed;

        for (auto y : state.y)
        {
            if (map[y][new_state.x] == '0')
                new_state.y.erase(std::find(new_state.y.begin(), new_state.y.end(), y));
        }

        if (new_state.y.size() > 0)
        {
            int casualties = (state.y.size() - new_state.y.size()) + decide(new_state).first;

            if (casualties == 0)
                return { 0, "JUMP" };

            if (casualties < min_casualties.first)
                min_casualties = { casualties, "JUMP" };
        }
    }

    if (std::find(state.y.begin(), state.y.end(), 0) == state.y.end())
    {
        State new_state = state;

        new_state.x += new_state.speed;
        new_state.y = {};

        for (auto y : state.y)
        {
            bool stil_alive = true;

            for (int x = state.x + 1; x <= new_state.x - 1; ++x)
            {
                if (map[y][x] == '0')
                {
                    stil_alive = false;

                    break;
                }
            }

            for (int x = state.x + 1; x <= new_state.x; ++x)
            {
                if (map[y - 1][x] == '0')
                {
                    stil_alive = false;

                    break;
                }
            }

            if (stil_alive)
                new_state.y.push_back(y - 1);
        }

        if (new_state.y.size() > 0)
        {
            int casualties = (state.y.size() - new_state.y.size()) + decide(new_state).first;

            if (casualties == 0)
                return { 0, "UP" };

            if (casualties < min_casualties.first)
                min_casualties = { casualties, "UP" };
        }
    }

    if (std::find(state.y.begin(), state.y.end(), map.size() - 1) == state.y.end())
    {
        State new_state = state;

        new_state.x += new_state.speed;
        new_state.y = {};

        for (auto y : state.y)
        {
            bool still_alive = true;

            for (int x = state.x + 1; x <= new_state.x - 1; ++x)
            {
                if (map[y][x] == '0')
                {
                    still_alive = false;

                    break;
                }
            }
            
            for (int x = state.x + 1; x <= new_state.x; ++x)
            {
                if (map[y + 1][x] == '0')
                {
                    still_alive = false;

                    break;
                }
            }

            if (still_alive)
                new_state.y.push_back(y + 1);
        }

        if (new_state.y.size() > 0)
        {
            int casualties = (state.y.size() - new_state.y.size()) + decide(new_state).first;

            if (casualties == 0)
                return { 0, "DOWN" };

            if (casualties < min_casualties.first)
                min_casualties = { casualties, "DOWN" };
        }
    }

    if (state.speed > 1)
    {
        State new_state = state;

        --new_state.speed;
        new_state.x += new_state.speed;

        for (auto y : state.y)
        {
            for (int x = state.x + 1; x <= new_state.x; ++x)
            {
                if (map[y][x] == '0')
                {
                    new_state.y.erase(std::find(new_state.y.begin(), new_state.y.end(), y));

                    break;
                }
            }
        }

        if (new_state.y.size() > 0)
        {
            int casualties = (state.y.size() - new_state.y.size()) + decide(new_state).first;

            if (casualties == 0)
                return { 0, "SLOW" };

            if (casualties < min_casualties.first)
                min_casualties = { casualties, "SLOW" };
        }
    }

    return min_casualties;
}

int main()
{
    int m, v;

    std::cin >> m; std::cin.ignore();
    std::cin >> v; std::cin.ignore();
    std::cin >> map[0]; std::cin.ignore();
    std::cin >> map[1]; std::cin.ignore();
    std::cin >> map[2]; std::cin.ignore();
    std::cin >> map[3]; std::cin.ignore();

    for (int i = 0; i < 4; ++i)
        last_hole = std::max(last_hole, (map[i].rfind('0') != std::string::npos) ? map[i].rfind('0') : 0);
        
    while (1)
    {
        State current_state;
        int s;

        std::cin >> s; std::cin.ignore();
        current_state.speed = s;

        for (int i = 0; i < m; ++i)
        {
            int x, y, a;

            std::cin >> x >> y >> a; std::cin.ignore();

            if (a)
            {
                current_state.y.push_back(y);
                current_state.x = x;
            }
        }

        std::cout << decide(current_state).second << std::endl;
    }
}