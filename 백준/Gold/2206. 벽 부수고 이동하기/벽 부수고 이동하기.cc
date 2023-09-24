#include <iostream>
#include <queue>
#include <tuple>

const int X_MAX = 1000;
const int Y_MAX = 1000;
const int POWER_MAX = 1;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char map[Y_MAX + 1][X_MAX + 1];
    int width, height;

    std::cin >> height >> width;
    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            std::cin >> map[y][x];
        }
    }

    auto is_valid = [width, height](int x, int y) -> bool {
        return x >= 1 && x <= width && y >= 1 && y <= height;
    };

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    std::queue<std::tuple<int, int, int, int>> queue;
    queue.push({1, 1, 1, 1});

    bool visited[Y_MAX + 1][X_MAX + 1][POWER_MAX + 1] = {false};
    while (queue.empty() == false) {
        auto [x, y, power, distance] = queue.front();
        queue.pop();

        if (x == width && y == height) {
            std::cout << distance;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny) == false || visited[ny][nx][power]) {
                continue;
            }
            visited[ny][nx][power] = true;

            if (map[ny][nx] == '0') {
                queue.push({nx, ny, power, distance + 1});
            } else if (power > 0) {
                queue.push({nx, ny, power - 1, distance + 1});
            }
        }
    }
    std::cout << "-1";
    return 0;
}
