// #include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>
#include <algorithm>

class Sequence
{
private:
    std::unordered_set<std::string> visited;
    std::string characters, sequence;
    std::vector<int> edges;
    int x, n;

    void dfs(const std::string& node)
    {
        for (int i = 0; i < x; ++i)
        {
            std::string temp = node + characters[i];

            if (visited.find(temp) == visited.end())
            {
                visited.insert(temp);
                dfs(temp.substr(1));
                edges.push_back(i);
            }
        }
    }

    void de_bruijn()
    {
        visited.clear();
        edges.clear();

        std::string starting_node = std::string(n - 1, characters[0]);

        dfs(starting_node);

        int l = pow(x, n);

        for (int i = 0; i < l; ++i)
            sequence += characters[edges[i]];

        sequence += starting_node;
    }

public:
    Sequence(const int& x, const int& n, const std::string& characters)
        : x(x), n(n), characters(characters)
    {
        de_bruijn();
    }

    void print()
    {
        reverse(sequence.begin(), sequence.end());
        std::cout << sequence << std::endl;
    }
};

int main()
{
    std::string characters;
    int x, n;

    std::cin >> x; std::cin.ignore();
    std::cin >> n; std::cin.ignore();

    for (int i = 0; i < x; ++i)
        characters += std::to_string(i);

    Sequence sequence(x, n, characters);

    sequence.print();
}