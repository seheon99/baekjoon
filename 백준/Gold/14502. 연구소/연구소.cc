#include <iostream>
#include <queue>
#include <utility>

constexpr int WALL_MAX = 3;

using pair = std::pair<int, int>;

static int board[8][8];
static int width;
static int height;
static int safearea = 0;

static int is_valid(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

static int count_safearea() {
    static const int dx[4] = {0, 1, 0, -1};
    static const int dy[4] = {1, 0, -1, 0};

    std::queue<pair> work;
    for (int yi = 0; yi < height; yi++) {
        for (int xi = 0; xi < width; xi++) {
            // if virus here,
            if (board[yi][xi] == 2) {
                work.push({xi, yi});
            }
        }
    }

    int count = 0;
    bool visited[8][8] = {false};
    while (!work.empty()) {
        auto [x, y] = work.front();
        work.pop();

        for (int i = 0; i < 4; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];

            if (is_valid(xi, yi) == false) {
                continue;
            }

            // if empty space and never visited,
            if (board[yi][xi] == 0 && visited[yi][xi] == false) {
                work.push({xi, yi});
                visited[yi][xi] = true;
                count++;
            }
        }
    }
    return safearea - count - WALL_MAX;
}

static int install_wall(int count_installed, int from) {
    if (count_installed == WALL_MAX) {
        return count_safearea();
    }

    int max = 0;

    while (from < width * height) {
        int wx = from % width;
        int wy = from / width;
        from += 1;

        // if not an empty space,
        if (board[wy][wx] != 0) {
            continue;
        }

        board[wy][wx] = 1;
        max = std::max(max, install_wall(count_installed + 1, from));
        board[wy][wx] = 0;
    }

    return max;
}

int main(void) {
    std::cin >> height >> width;
    for (int yi = 0; yi < height; yi++) {
        for (int xi = 0; xi < width; xi++) {
            std::cin >> board[yi][xi];
            if (board[yi][xi] == 0) {
                safearea += 1;
            }
        }
    }
    std::cout << install_wall(0, 0);
    return 0;
}
