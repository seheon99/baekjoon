#include <cstring>
#include <iostream>

static const int MAX_CHAPTER = 500;

static int n_chapters;
static int pages[MAX_CHAPTER];

static int page_acc[MAX_CHAPTER];
static int cache[MAX_CHAPTER][MAX_CHAPTER];

static int merge(int from, int to) {
  if (from == to) {
    return 0;
  }

  if (from + 1 == to) {
    return pages[from] + pages[to];
  }

  int &answer = cache[from][to];
  if (answer == 0) {
    answer = INT32_MAX;
    for (int i = from; i < to; i++) {
      answer =
          std::min(answer, merge(from, i) + merge(i + 1, to) +
                               (page_acc[to] - page_acc[from] + pages[from]));
    }
  }
  return answer;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int testcase;
  std::cin >> testcase;

  while (--testcase >= 0) {
    memset(cache, 0, sizeof(int) * MAX_CHAPTER * MAX_CHAPTER);

    std::cin >> n_chapters;
    for (int i = 0; i < n_chapters; i++) {
      std::cin >> pages[i];
    }
    page_acc[0] = pages[0];
    for (int i = 1; i < n_chapters; i++) {
      page_acc[i] = page_acc[i - 1] + pages[i];
    }

    std::cout << merge(0, n_chapters - 1) << '\n';
  }

  return 0;
}