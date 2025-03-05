#include <iostream>

static const int MAX_MATRICIES = 500;

static int n_matricies;
static int n_cols[MAX_MATRICIES];
static int n_rows[MAX_MATRICIES];

static int multiply(int from, int to) {
  static int cache[MAX_MATRICIES][MAX_MATRICIES];

  if (from == to) {
    return 0;
  }

  int &answer = cache[from][to];

  if (answer == 0) {
    answer = INT32_MAX;
    for (int i = from; i < to; i++) {
      answer = std::min(answer, multiply(from, i) + multiply(i + 1, to) +
                                    (n_cols[from] * n_rows[i] * n_rows[to]));
    }
  }

  return answer;
}

int main(void) {
  std::cin >> n_matricies;
  for (int i = 0; i < n_matricies; i++) {
    std::cin >> n_cols[i] >> n_rows[i];
  }
  std::cout << multiply(0, n_matricies - 1);

  return 0;
}