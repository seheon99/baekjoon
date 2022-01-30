#include <iostream>

int main(void) {
  int n, sum = 0, max = 0;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int score;
    std::cin >> score;
    sum += score;
    max = (score > max ? score : max);
  }
  std::cout << (double) sum / n / max * 100;
}
