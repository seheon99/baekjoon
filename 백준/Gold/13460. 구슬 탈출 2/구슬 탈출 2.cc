#include <iostream>
#include <queue>
#include <tuple>

using coord = std::pair<int, int>;

static const char EMPTY = '.';
static const char WALL = '#';
static const char HOLE = 'O';
static const char RED = 'R';
static const char BLUE = 'B';

static const int MAX_WIDTH = 10;
static const int MAX_HEIGHT = 10;

static const int dx[] = {1, -1, 0, 0};
static const int dy[] = {0, 0, 1, -1};

static int width, height;
static char map[MAX_HEIGHT][MAX_WIDTH];

static bool is_movable(const coord& me, const coord& other, int dx, int dy) {
  auto [mx, my] = me;
  auto [ox, oy] = other;

  if (map[my + dy][mx + dx] == WALL) {
    return false;
  }

  if (my + dy == oy && mx + dx == ox && map[my + dy * 2][mx + dx * 2] == WALL) {
    return false;
  }

  return true;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> height >> width;

  coord red, blue;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      std::cin >> map[y][x];
      if (map[y][x] == RED) {
        red = {x, y};
        map[y][x] = '.';
      } else if (map[y][x] == BLUE) {
        blue = {x, y};
        map[y][x] = '.';
      }
    }
  }

  std::queue<std::tuple<coord, coord, int>> queue;
  queue.push({red, blue, 1});

  bool ok = false;

  while (!queue.empty() && !ok) {
    auto [red, blue, count] = queue.front();
    queue.pop();

    for (int i = 0; i < 4; i++) {
      if (!is_movable(red, blue, dx[i], dy[i]) &&
          !is_movable(blue, red, dx[i], dy[i])) {
        continue;
      }

      coord r = red;
      coord b = blue;
      bool red_ok = false;
      bool blue_ok = false;
      bool moved;
      do {
        moved = false;
        if (is_movable(r, blue_ok ? coord(0, 0) : b, dx[i], dy[i])) {
          r = {r.first + dx[i], r.second + dy[i]};
          red_ok = red_ok || map[r.second][r.first] == HOLE;
          moved = true;
        }
        if (is_movable(b, red_ok ? coord(0, 0) : r, dx[i], dy[i])) {
          b = {b.first + dx[i], b.second + dy[i]};
          blue_ok = blue_ok || map[b.second][b.first] == HOLE;
          moved = true;
        }
      } while (moved);

      if (red_ok && !blue_ok) {
        std::cout << count;
        ok = true;
        break;
      } else if (blue_ok) {
        continue;
      }

      if (count < 10) {
        queue.push({r, b, count + 1});
      }
    }
  }

  if (!ok) {
    std::cout << -1;
  }

  return 0;
}