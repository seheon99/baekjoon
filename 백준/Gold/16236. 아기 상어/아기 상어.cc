#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using tuple = std::tuple<int, int, int>; // t, y, x

static constexpr int dx[4] = {0, -1, 1, 0};
static constexpr int dy[4] = {-1, 0, 0, 1};

int n;
int map[20][20];

static tuple eat(int x0, int y0, int size) {
    std::queue<tuple> work;
    bool visited[20][20] = {};

    int t_option = 0;
    std::vector<tuple> option;

    work.push({0, y0, x0});
    visited[y0][x0] = true;
    while (!work.empty()) {
        auto [t, yt, xt] = work.front();
        work.pop();

        if (t_option > 0 && t > t_option) {
            break;
        } else if (map[yt][xt] != 0 && map[yt][xt] != 9 && map[yt][xt] < size) {
            t_option = t;
            option.push_back({t, yt, xt});
        }

        for (int i = 0; i < 4; i++) {
            int xi = xt + dx[i];
            int yi = yt + dy[i];

            if (xi < 0 || xi >= n || yi < 0 || yi >= n) {
                continue;
            } else if (visited[yi][xi]) {
                continue;
            }

            if (map[yi][xi] <= size) {
                work.push({t + 1, yi, xi});
                visited[yi][xi] = true;
            }
        }
    }
    if (t_option > 0) {
        return *std::min_element(option.begin(), option.end());
    } else {
        return {-1, -1, -1};
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    int x0, y0;
    for (int yi = 0; yi < n; yi++) {
        for (int xi = 0; xi < n; xi++) {
            std::cin >> map[yi][xi];
            if (map[yi][xi] == 9) {
                x0 = xi;
                y0 = yi;
            }
        }
    }

    int x = x0;
    int y = y0;
    int size = 2;
    int count = 0;
    int tot = 0;
    while (true) {
        auto [t, yt, xt] = eat(x, y, size);

        if (t == -1) {
            break;
        }

        count += 1;
        if (count == size) {
            size += 1;
            count = 0;
        }

        map[y][x] = 0;
        map[yt][xt] = 9;
        x = xt;
        y = yt;
        tot += t;
    }
    std::cout << tot;
    return 0;
}
