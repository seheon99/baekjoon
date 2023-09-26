#include <iostream>
#include <queue>
#include <vector>

const int N_MAX = 10001;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> edges[N_MAX];
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2, l;
        std::cin >> v1 >> v2 >> l;
        edges[v1].push_back({v2, l});
        edges[v2].push_back({v1, l});
    }

    int final_point = 1;
    int final_length = 0;
    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < 2; i++)
    {

        bool visited[N_MAX] = {false};
        visited[final_point] = true;
        queue.push({final_point, 0});
        while (queue.empty() == false)
        {
            auto [current_point, current_length] = queue.front();
            queue.pop();

            for (auto [target_point, distance] : edges[current_point])
            {
                if (visited[target_point])
                {
                    continue;
                }

                if (current_length + distance > final_length)
                {
                    final_length = current_length + distance;
                    final_point = target_point;
                }
                visited[target_point] = true;
                queue.push({target_point, current_length + distance});
            }
        }
    }
    std::cout << final_length;
    return 0;
}