#include <iostream>
#include <queue>
#include <utility>

using pair = std::pair<int, int>;

int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    int map[101] = {0};
    for (int i = 0; i < n + m; i++) {
        int from, to;
        std::cin >> from >> to;

        map[from] = to;
    }

    std::queue<pair> work;
    bool visited[101] = {false};

    work.push({1, 0});
    visited[1] = true;
    while (!work.empty()) {
        auto [x, t] = work.front();
        work.pop();

        if (x == 100) {
            std::cout << t;
            break;
        }

        for (int dx = 1; dx <= 6; dx++) {
            int xi = x + dx;
            if (xi > 100) {
                break;
            }

            while (map[xi] != 0) {
                xi = map[xi];
            }
            if (visited[xi] == false) {
                work.push({xi, t + 1});
                visited[xi] = true;
            }
        }
    }

    return 0;
}
