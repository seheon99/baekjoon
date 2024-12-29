#include <utility>
#include <iostream>
#include <algorithm>

int map_size;
int n_coords;
std::pair<int, int> coords[1002];
int traces[1002][1002];

int distance(int i1, int i2) {
    return std::abs(coords[i1].first - coords[i2].first) +
           std::abs(coords[i1].second - coords[i2].second);
}

int dp(int c1, int c2) {
    if (c1 == n_coords + 1 || c2 == n_coords + 1) {
        return 0;
    }

    static int cache[1002][1002];
    int& answer = cache[c1][c2];

    if (answer == 0) {
        int next = std::max(c1, c2) + 1;
        int c1_distance = dp(next, c2) + distance(c1, next);
        int c2_distance = dp(c1, next) + distance(c2, next);
        if (c1_distance < c2_distance) {
            answer = c1_distance;
            traces[c1][c2] = 1;
        } else {
            answer = c2_distance;
            traces[c1][c2] = 2;
        }
    }
    return answer;
}

int main(void) {
    std::cin >> map_size >> n_coords;
    coords[0] = {1, 1};
    coords[1] = {map_size, map_size};
    for (int i = 2; i < n_coords + 2; i++) {
        std::cin >> coords[i].first >> coords[i].second;
    }
    std::cout << dp(0, 1) << '\n';

    int c1 = 0;
    int c2 = 1;
    for (int i = 2; i < n_coords + 2; i++) {
        std::cout << traces[c1][c2] << '\n';
        if (traces[c1][c2] == 1) {
            c1 = i;
        } else {
            c2 = i;
        }
    }
    return 0;
}