#include <iostream>
#include <queue>

int main(void)
{
    int a, b;
    std::cin >> a >> b;

    std::queue<std::pair<long, int>> queue;
    queue.push({a, 1});
    while (queue.empty() == false)
    {
        auto [current, n] = queue.front();
        queue.pop();

        long candidates[] = {current * 2, current * 10 + 1};
        for (auto next : candidates)
        {
            if (next == b)
            {
                std::cout << n + 1;
                return 0;
            }
            else if (next < b)
            {
                queue.push({next, n + 1});
            }
        }
    }
    std::cout << -1;
    return 0;
}