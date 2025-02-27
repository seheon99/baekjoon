#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int count[10] = {0};
  int add = 0;

  for (int i = 1; n != 0; i *= 10) {
    int k = n % 10;
    n /= 10;

    count[0] -= i;
    for (int j = 0; j < k; j++) {
      count[j] += (n + 1) * i;
    }

    count[k] += n * i + 1 + add;
    for (int j = k + 1; j <= 9; j++) {
      count[j] += n * i;
    }

    add += k * i;
  }

  for (int i = 0; i < 10; i++) {
    std::cout << count[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
