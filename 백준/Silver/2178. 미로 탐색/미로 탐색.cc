#include <iostream>
#include <queue>
#include <utility>

using pair = std::pair<int, int>;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nx, ny;
    std::cin >> ny >> nx;

    int map[ny][nx];
    for (int yi = 0; yi < ny; yi++) {
        for (int xi = 0; xi < nx; xi++) {
            char ch;
            std::cin >> ch;
            map[yi][xi] = ch == '0' ? -1 : 0;
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    std::queue<pair> work;
    map[0][0] = 1;
    work.push(std::make_pair(0, 0));

    while (work.empty() == false) {
        pair coord = work.front();
        work.pop();

        int x = std::get<0>(coord);
        int y = std::get<1>(coord);

        if (x == nx - 1 && y == ny - 1) {
            std::cout << map[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];

            if (xi >= 0 && xi < nx && yi >= 0 && yi < ny && map[yi][xi] == 0) {
                map[yi][xi] = map[y][x] + 1;
                work.push(std::make_pair(xi, yi));
            }
        }
    }

    return 0;
}
