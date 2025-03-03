#include <iostream>

static const int N_MAX = 500;
static const int dx[] = {1, -1, 0, 0};
static const int dy[] = {0, 0, 1, -1};

static int map[N_MAX][N_MAX];
static int width;
static int height;

static int count(int x, int y) {
  static int cache[N_MAX][N_MAX] = {1};

  if (x < 0 || x >= width || y < 0 || y >= height) {
    return 0;
  }

  int &answer = cache[y][x];
  if (!answer) {
    for (int i = 0; i < 4; i++) {
      if (map[y][x] < map[y + dy[i]][x + dx[i]]) {
        int subcount = count(x + dx[i], y + dy[i]);
        if (subcount > 0) {
          answer += subcount;
        }
      }
    }
    if (answer == 0) {
      answer = -1;
    }
  }
  return answer;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> height >> width;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      std::cin >> map[y][x];
    }
  }

  std::cout << std::max(0, count(width - 1, height - 1)) << '\n';
  return 0;
}