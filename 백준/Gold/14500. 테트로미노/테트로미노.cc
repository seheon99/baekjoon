#include <algorithm>
#include <iostream>
#include <numeric>

static constexpr int MIN_SCORE = -9999;

static int height;
static int width;
static int board[500][500];

static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, -1, 0, 1};

static bool is_valid(int x, int y) {
    return 0 <= x && x < width && 0 <= y && y < height;
}

static bool is_visited(int x, int y) { return board[y][x] == MIN_SCORE; }

static int get_maxscore(int x, int y, int step) {
    int self_score = board[y][x];
    if (step == 4) {
        return self_score;
    }

    board[y][x] = MIN_SCORE;

    int max_score = MIN_SCORE;
    if (step == 1) {
        // for T shape
        //  1
        // 2X0
        //  3
        int option[4] = {MIN_SCORE, MIN_SCORE, MIN_SCORE, MIN_SCORE};

        for (int i = 0; i < 4; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];

            if (is_valid(xi, yi)) {
                option[i] = board[yi][xi];
            }
        }
        max_score = self_score + std::accumulate(option, option + 4, 0) -
                    *std::min_element(option, option + 4);
    }
    for (int i = 0; i < 4; i++) {
        int xi = x + dx[i];
        int yi = y + dy[i];

        if (!is_valid(xi, yi) || is_visited(xi, yi)) {
            continue;
        } else {
            int option = get_maxscore(xi, yi, step + 1);
            if (max_score < self_score + option) {
                max_score = self_score + option;
            }
        }
    }

    board[y][x] = self_score;

    return max_score;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> height >> width;
    for (int yi = 0; yi < height; yi++) {
        for (int xi = 0; xi < width; xi++) {
            std::cin >> board[yi][xi];
        }
    }

    int max_score = 0;
    for (int yi = 0; yi < height; yi++) {
        for (int xi = 0; xi < width; xi++) {
            max_score = std::max(max_score, get_maxscore(xi, yi, 1));
        }
    }
    std::cout << max_score;
    return 0;
}
