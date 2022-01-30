#include <iostream>
#include <cmath>

int main(void) {
  int size, n1, n2;

  std::cin >> size >> n1 >> n2;

  for (int scale = 2, pow = 1; scale < size * 2; scale *= 2, pow++) {
    if ((n1 - 1) / scale == (n2 - 1) / scale) {
      std::cout << pow;
      return (0);
    }
  }
  std::cout << -1;
  return (0);
}
