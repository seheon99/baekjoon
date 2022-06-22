#include <algorithm>
#include <iostream>
#include <vector>

static int N;
static std::vector<int> jump_length;

static int get_path_length(int start_point) {
  static int cache[1000];
  static bool cached[1000];

  if (start_point == N - 1) {
    return 0;
  }

  if (cached[start_point] == false) {
    int &length = cache[start_point];
    cached[start_point] = true;

    length = -1;
    for (int i = 1; i <= jump_length[start_point]; i++) {
      if (start_point + i > N - 1) {
        break;
      }
      int prev_length = get_path_length(start_point + i);
      if (prev_length != -1) {
        length = std::min<unsigned int>(length, prev_length + 1);
      }
    }
  }
  return cache[start_point];
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  jump_length.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> jump_length[i];
  }
  std::cout << get_path_length(0);
}
