#include <cstring>
#include <iostream>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int map[n + 1][n + 1];
    std::memset(map, 0, sizeof(int) * (n + 1) * (n + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            std::cin >> map[y][x];
            map[y][x] += map[y][x - 1] + map[y - 1][x] - map[y - 1][x - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        std::cin >> y1 >> x1 >> y2 >> x2;
        std::cout << map[y2][x2] + map[y1 - 1][x1 - 1] -
                         (map[y2][x1 - 1] + map[y1 - 1][x2])
                  << '\n';
    }
    return 0;
}
