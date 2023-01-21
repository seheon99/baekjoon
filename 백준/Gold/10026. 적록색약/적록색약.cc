#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

static constexpr int dx[4] = {1, 0, -1, 0};
static constexpr int dy[4] = {0, -1, 0, 1};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    char map[100][101];
    for (int i = 0; i < n; i++) {
        std::cin >> map[i];
    }

    int count_rgb = 0;
    bool check[100][101] = {};
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (check[y][x] == false) {
                char color = map[y][x];
                count_rgb += 1;

                std::queue<std::pair<int, int>> work;
                work.push({x, y});
                check[y][x] = true;
                while (!work.empty()) {
                    auto coord = work.front();
                    int x = coord.first;
                    int y = coord.second;
                    work.pop();

                    for (int i = 0; i < 4; i++) {
                        int xi = x + dx[i];
                        int yi = y + dy[i];

                        if (xi >= 0 && xi < n && yi >= 0 && yi < n &&
                            check[yi][xi] == false) {
                            if (map[yi][xi] == color) {
                                work.push({xi, yi});
                                check[yi][xi] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    int count_rg_b = 0;
    std::memset(check, 0, sizeof(check));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (check[y][x] == false) {
                char color = map[y][x];
                count_rg_b += 1;

                std::queue<std::pair<int, int>> work;
                work.push({x, y});
                check[y][x] = true;
                while (!work.empty()) {
                    auto coord = work.front();
                    int x = coord.first;
                    int y = coord.second;
                    work.pop();

                    for (int i = 0; i < 4; i++) {
                        int xi = x + dx[i];
                        int yi = y + dy[i];

                        if (xi >= 0 && xi < n && yi >= 0 && yi < n &&
                            check[yi][xi] == false) {
                            if (map[yi][xi] == color ||
                                ((color == 'R' || color == 'G') &&
                                 (map[yi][xi] == 'R' || map[yi][xi] == 'G'))) {
                                work.push({xi, yi});
                                check[yi][xi] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << count_rgb << ' ' << count_rg_b << '\n';
    return 0;
}
