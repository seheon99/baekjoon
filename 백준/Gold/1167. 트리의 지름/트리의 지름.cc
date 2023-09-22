#include <iostream>
#include <map>
#include <queue>

const int MAX_VERTEX = 100001;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, int> edges[MAX_VERTEX];

    int n_vertex;
    std::cin >> n_vertex;
    for (int i = 0; i < n_vertex; i++) {
        int x;
        std::cin >> x;

        int y;
        while (std::cin >> y, y != -1) {
            int length;
            std::cin >> length;
            edges[x].insert({y, length});
        }
    }

    int final_vertex = 1;
    int final_length = 0;
    for (int i = 0; i < 2; i++) {
        std::queue<std::pair<int, int>> queue({{final_vertex, 0}});
        bool visited[MAX_VERTEX] = {false};
        visited[final_vertex] = true;
        while (queue.empty() == false) {
            auto [vertex, length] = queue.front();
            queue.pop();

            if (final_length < length) {
                final_vertex = vertex;
                final_length = length;
            }
            for (auto [v, l] : edges[vertex]) {
                if (visited[v] == false) {
                    visited[v] = true;
                    queue.push({v, length + l});
                }
            }
        }
    }
    std::cout << final_length;
    return 0;
}
