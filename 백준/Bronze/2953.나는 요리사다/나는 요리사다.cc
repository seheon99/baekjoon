#include <iostream>
#include <utility>

int main(void) {
  std::pair<int, int> sol = {0, 0};

  for (int i = 1; i <= 5; i++) {
    int score[4], sum;

    std::cin >> score[0] >> score[1] >> score[2] >> score[3];
    sum = score[0] + score[1] + score[2] + score[3];
    if (sum > sol.second) {
      sol.first = i;
      sol.second = sum;
    }
  }
  std::cout << sol.first << " " << sol.second;
  return (0);
}
