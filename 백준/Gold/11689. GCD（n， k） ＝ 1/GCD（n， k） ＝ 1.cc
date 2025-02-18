#include <cmath>
#include <iostream>

using number = long;

const number N_MAX = 1'000'000'000'000;

int main(void) {
  number n;
  std::cin >> n;

  number answer = n;
  for (number i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      answer = answer / i * (i - 1);
      while (n % i == 0) {
        n /= i;
      }
    }
  }

  if (n > 1) {
    answer = answer / n * (n - 1);
  }

  std::cout << answer << '\n';

  return 0;
}