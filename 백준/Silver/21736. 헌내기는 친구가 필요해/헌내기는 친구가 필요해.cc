#include <iostream>
#include <queue>

struct coord {
    int x;
    int y;
};

typedef struct coord coord_t;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main(void) {
    std::queue<coord> queue;
    char map[600][600];

    int height, width;
    std::cin >> height >> width;
    for (int y = 0; y < height; y++) {
        std::cin >> map[y];
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[y][x] == 'I') {
                map[y][x] = 'X';
                queue.push({x, y});
                break;
            }
        }
        if (queue.size() == 1) {
            break;
        }
    }

    int count = 0;
    while (queue.size() > 0) {
        int x = queue.front().x;
        int y = queue.front().y;
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                switch (map[ny][nx]) {
                case 'P':
                    count++;
                case 'O':
                    map[ny][nx] = 'X';
                    queue.push({nx, ny});
                }
            }
        }
    }

    if (count == 0) {
        std::cout << "TT";
    } else {
        std::cout << count;
    }

    return 0;
}
