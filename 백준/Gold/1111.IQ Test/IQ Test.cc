#include <iostream>

int main(void) {
  int n;
  int array[50];

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  if (n == 1 || n == 2 && array[0] != array[1]) {
    std::cout << "A";
  } else if (n == 2 && array[0] == array[1]) {
    std::cout << array[0];
  } else {
    double a, b;

    if (array[1] == array[0]) {
      a = 1; b = 0;
    } else {
      a = (double) (array[2] - array[1]) / (array[1] - array[0]);
      b = array[1] - a * array[0];
    }

    if (a != (int)a || b != (int)b) {
      std::cout << "B";
    } else {
      for (int i = 1; i < n; i++) {
        if (a * array[i - 1] + b != array[i]) {
          std::cout << "B";
          break ;
        } else if (i == n - 1) {
          std::cout << a * array[i] + b;
        }
      }
    }
  }
  return 0;
}
