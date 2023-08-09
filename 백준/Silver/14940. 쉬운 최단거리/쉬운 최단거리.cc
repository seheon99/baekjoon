#include <deque>
#include <iostream>

struct Coord {
    int x;
    int y;

    Coord(int x, int y) : x(x), y(y) {}
};

const Coord d[4] = {
    Coord(-1, 0),
    Coord(1, 0),
    Coord(0, -1),
    Coord(0, 1),
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nx, ny;
    std::cin >> ny >> nx;

    const int MAX_X = 1000;
    const int MAX_Y = 1000;

    int tx, ty;

    int map[MAX_Y][MAX_X] = {0};
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            int n;
            std::cin >> n;

            map[y][x] = n == 1;
            if (n == 2) {
                ty = y;
                tx = x;
            } else if (n == 1) {
                map[y][x] = -1;
            }
        }
    }

    std::deque<Coord> queue = {Coord(tx, ty)};
    while (queue.empty() == false) {
        Coord &now = queue.front();

        for (int i = 0; i < 4; i++) {
            int x = now.x + d[i].x;
            int y = now.y + d[i].y;

            if (x >= 0 && x < nx && y >= 0 && y < ny && map[y][x] == -1) {
                map[y][x] = map[now.y][now.x] + 1;
                queue.push_back(Coord(x, y));
            }
        }

        queue.pop_front();
    }

    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            std::cout << map[y][x] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
