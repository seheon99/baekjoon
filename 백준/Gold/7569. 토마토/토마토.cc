#include <iostream>
#include <queue>
#include <tuple>

using tuple = std::tuple<int, int, int>;

constexpr int dx[6] = {0, 0, 1, -1, 0, 0};
constexpr int dy[6] = {0, 0, 0, 0, 1, -1};
constexpr int dz[6] = {1, -1, 0, 0, 0, 0};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int xmax, ymax, zmax;
    std::cin >> xmax >> ymax >> zmax;

    std::queue<tuple> work;
    int remain = 0;
    int days = 0;

    int map[zmax][ymax][xmax];
    for (int zi = 0; zi < zmax; zi++) {
        for (int yi = 0; yi < ymax; yi++) {
            for (int xi = 0; xi < xmax; xi++) {
                std::cin >> map[zi][yi][xi];
                if (map[zi][yi][xi] == 1) {
                    work.push(std::make_tuple(xi, yi, zi));
                } else if (map[zi][yi][xi] == 0) {
                    remain++;
                }
            }
        }
    }

    while (!work.empty()) {
        tuple front = work.front();
        work.pop();

        int x = std::get<0>(front);
        int y = std::get<1>(front);
        int z = std::get<2>(front);

        for (int i = 0; i < 6; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            int zi = z + dz[i];

            if (xi < 0 || xi >= xmax) {
                continue;
            } else if (yi < 0 || yi >= ymax) {
                continue;
            } else if (zi < 0 || zi >= zmax) {
                continue;
            }

            if (map[zi][yi][xi] == 0) {
                remain--;
                days = std::max(days, map[z][y][x]);
                map[zi][yi][xi] = map[z][y][x] + 1;
                work.push(std::make_tuple(xi, yi, zi));
            }
        }
    }

    if (remain > 0) {
        std::cout << "-1";
    } else {
        std::cout << days;
    }

    return 0;
}
