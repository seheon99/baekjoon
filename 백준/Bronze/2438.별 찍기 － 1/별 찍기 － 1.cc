#include <iostream>

int main(void) {
  int n;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << "*";
    }
    if (i != n - 1)
      std::cout << std::endl;
  }
  return (0);
}
