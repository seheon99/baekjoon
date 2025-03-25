#include <iostream>
#include <queue>

static const int MAX_LEVEL = 100;
static const int N_MAX = 100;
static const int dx[] = {1, -1, 0, 0};
static const int dy[] = {0, 0, 1, -1};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int map[N_MAX][N_MAX];
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      std::cin >> map[y][x];
    }
  }

  int answer = 1;

  for (int level = 1; level <= MAX_LEVEL; ++level) {
    bool visited[N_MAX][N_MAX] = {false};
    int count = 0;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        if (visited[y][x]) {
          continue;
        }
        visited[y][x] = true;

        if (map[y][x] <= level) {
          continue;
        }

        ++count;

        std::queue<std::pair<int, int>> queue;
        queue.push({x, y});
        while (!queue.empty()) {
          auto [x, y] = queue.front();
          queue.pop();

          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
              continue;
            }

            if (visited[ny][nx]) {
              continue;
            }
            visited[ny][nx] = true;

            if (map[ny][nx] > level) {
              queue.push({nx, ny});
            }
          }
        }
      }
    }
    answer = std::max(answer, count);
  }

  std::cout << answer << std::endl;

  return 0;
}