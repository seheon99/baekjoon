#include <cstring>
#include <iostream>
#include <vector>

static const int STRUCTURE_MAX = 1000;

static int build_time[STRUCTURE_MAX + 1];
static std::vector<int> requirements[STRUCTURE_MAX + 1];
static int cache[STRUCTURE_MAX + 1];

int get_delay(int structure_no) {
  int &answer = cache[structure_no];

  if (answer == -1) {
    answer = build_time[structure_no];
    for (auto requirement : requirements[structure_no]) {
      answer =
          std::max(answer, get_delay(requirement) + build_time[structure_no]);
    }
  }

  return answer;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_testcases;
  std::cin >> n_testcases;

  int n_structures = 0;
  int n_requirements;
  int target_structure_no;

  while (--n_testcases >= 0) {
    memset(cache, -1, sizeof(int) * (STRUCTURE_MAX + 1));
    for (int i = 1; i <= n_structures; i++) {
      requirements[i].resize(0);
      requirements[i].reserve(STRUCTURE_MAX);
    }

    std::cin >> n_structures >> n_requirements;
    for (int i = 1; i <= n_structures; i++) {
      std::cin >> build_time[i];
    }
    for (int i = 0; i < n_requirements; i++) {
      int x, y;
      std::cin >> x >> y;
      requirements[y].push_back(x);
    }
    std::cin >> target_structure_no;
    std::cout << get_delay(target_structure_no) << '\n';
  }

  return 0;
}