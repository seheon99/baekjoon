#include <iostream>
#include <queue>
#include <tuple>

static const int MAX_LENGTH = 300;
static const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
static const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  while (--n >= 0) {
    int length;
    std::cin >> length;

    int from_x, from_y, to_x, to_y;
    std::cin >> from_x >> from_y >> to_x >> to_y;

    bool visited[MAX_LENGTH][MAX_LENGTH] = {false};
    visited[from_y][from_x] = true;

    std::queue<std::tuple<int, int, int>> queue;
    queue.push({from_x, from_y, 0});
    while (!queue.empty()) {
      auto [cx, cy, count] = queue.front();
      queue.pop();

      if (cx == to_x && cy == to_y) {
        std::cout << count << '\n';
        break;
      }

      for (int i = 0; i < 8; i++) {
        int x = cx + dx[i];
        int y = cy + dy[i];

        if (x < 0 || x >= length || y < 0 || y >= length) {
          continue;
        }
        if (visited[y][x]) {
          continue;
        }

        visited[y][x] = true;
        queue.push({x, y, count + 1});
      }
    }
  }

  return 0;
}