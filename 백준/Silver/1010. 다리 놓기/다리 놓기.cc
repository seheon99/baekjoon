#include <iostream>

static const int N_MAX = 30;

static int combination(int k, int n) {
  static int cache[N_MAX][N_MAX];

  if (k == 0 || k == n) {
    return 1;
  }

  if (k > n / 2) {
    k = n - k;
  }

  int &answer = cache[k][n];
  if (!answer) {
    answer = combination(k - 1, n - 1) + combination(k, n - 1);
  }
  return answer;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_testcases;
  std::cin >> n_testcases;

  while (--n_testcases >= 0) {
    int n_east, n_west;
    std::cin >> n_west >> n_east;
    std::cout << combination(n_west, n_east) << '\n';
  }

  return 0;
}