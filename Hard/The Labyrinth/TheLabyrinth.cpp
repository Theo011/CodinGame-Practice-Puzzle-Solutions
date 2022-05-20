#include <iostream>
#include <vector>
#include <limits>
#include <stack>

int r, c, a;

struct Coord
{
    int x, y;
};

std::vector<Coord> get_neighbours(const std::vector<std::vector<char>>& maze, const Coord& target)
{
    if (maze[target.y][target.x] == '?')
    {
        return {};
    }
    else
    {
        std::vector<Coord> neighbours;

        if (maze[target.y][target.x - 1] != '#')
            neighbours.push_back({ target.x - 1, target.y });

        if (maze[target.y][target.x + 1] != '#')
            neighbours.push_back({ target.x + 1, target.y });

        if (maze[target.y - 1][target.x] != '#')
            neighbours.push_back({ target.x, target.y - 1 });

        if (maze[target.y + 1][target.x] != '#')
            neighbours.push_back({ target.x, target.y + 1 });

        return neighbours;
    }
}

std::vector<Coord> dijkstra(const std::vector<std::vector<char>>& maze, const Coord& start, const char& end)
{
    auto prev = std::vector<std::vector<Coord>>(r, std::vector<Coord>(c, { std::numeric_limits<int>::max(), std::numeric_limits<int>::max() }));
    auto distances = std::vector<std::vector<int>>(r, std::vector<int>(c, std::numeric_limits<int>::max()));
    std::vector<Coord> unvisited;

    distances[start.y][start.x] = 0;

    for (int y = 0; y < r; ++y)
        for (int x = 0; x < c; ++x)
            unvisited.push_back({ x, y });

    while (!unvisited.empty())
    {
        std::vector<Coord>::iterator min_it = unvisited.begin();
        int min_dist = std::numeric_limits<int>::max();

        for (auto it = unvisited.begin(); it != unvisited.end(); ++it)
            if (distances[it->y][it->x] < min_dist)
            {
                min_dist = distances[it->y][it->x];
                min_it = it;
            }

        if (min_dist == std::numeric_limits<int>::max())
            return {};

        Coord target = *min_it;

        unvisited.erase(min_it);

        if (maze[target.y][target.x] == end)
        {
            std::vector<Coord> result;
            std::stack<Coord> path;
            Coord next = target;

            while (prev[next.y][next.x].x != std::numeric_limits<int>::max() && prev[next.y][next.x].y != std::numeric_limits<int>::max())
            {
                path.push(next);
                next = prev[next.y][next.x];
            }

            while (!path.empty())
            {
                result.push_back(path.top());
                path.pop();
            }

            return result;
        }

        std::vector<Coord> neighbours = get_neighbours(maze, target);

        for (auto neighbour : neighbours)
        {
            int alt = distances[target.y][target.x] + 1;

            if (alt < distances[neighbour.y][neighbour.x])
            {
                distances[neighbour.y][neighbour.x] = alt;
                prev[neighbour.y][neighbour.x] = target;
            }
        }
    }

    return {};
}

int main()
{
    bool control_room_visited = false;

    std::cin >> r >> c >> a; std::cin.ignore();

    while (1)
    {
        std::vector<std::vector<char>> maze(r, std::vector<char>(c));
        std::vector<Coord> path;
        int kr, kc;
    
        std::cin >> kr >> kc; std::cin.ignore();

        for (int i = 0; i < r; ++i)
        {
            std::string row;

            std::cin >> row; std::cin.ignore();

            for (int j = 0; j < c; ++j)
                maze[i][j] = row[j];
        }

        if (maze[kr][kc] == 'C')
            control_room_visited = true;

        if (control_room_visited)
        {
            path = dijkstra(maze, {kc, kr}, 'T');
        }
        else
        {
            path = dijkstra(maze, {kc, kr}, 'C');

            if (path.empty())
                path = dijkstra(maze, {kc, kr}, '?');
        }

        if (path[0].x > kc)
            std::cout << "RIGHT" << std::endl;
        else if (path[0].x < kc)
            std::cout << "LEFT" << std::endl;
        else if (path[0].y > kr)
            std::cout << "DOWN" << std::endl;
        else
            std::cout << "UP" << std::endl;
    }
}