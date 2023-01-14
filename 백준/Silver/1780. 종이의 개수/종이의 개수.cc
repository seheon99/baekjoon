#include <iostream>
#include <tuple>

using tuple = std::tuple<int, int, int>;

constexpr int THREE_SEVEN = 2187;

static int n;
static int map[THREE_SEVEN][THREE_SEVEN];

static bool check(int x, int y, int size) {
    for (int yi = y; yi < y + size; yi++) {
        for (int xi = x; xi < x + size; xi++) {
            if (map[yi][xi] != map[y][x]) {
                return false;
            }
        }
    }
    return true;
}

static tuple count(int x, int y, int size) {
    int n = map[y][x];

    if (check(x, y, size)) {
        if (n == -1) {
            return std::make_tuple(1, 0, 0);
        } else if (n == 0) {
            return std::make_tuple(0, 1, 0);
        } else if (n == 1) {
            return std::make_tuple(0, 0, 1);
        }
    }

    int nn = 0;
    int nz = 0;
    int np = 0;
    int gap = size / 3;

    for (int yi = y; yi < y + size; yi += gap) {
        for (int xi = x; xi < x + size; xi += gap) {
            tuple n = count(xi, yi, gap);
            nn += std::get<0>(n);
            nz += std::get<1>(n);
            np += std::get<2>(n);
        }
    }

    return std::make_tuple(nn, nz, np);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            std::cin >> map[y][x];
        }
    }

    tuple result = count(0, 0, n);
    std::cout << std::get<0>(result) << '\n';
    std::cout << std::get<1>(result) << '\n';
    std::cout << std::get<2>(result) << '\n';
    return 0;
}
