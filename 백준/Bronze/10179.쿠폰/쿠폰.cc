#include <iostream>
#include <iomanip>

int main(void) {
  int number;

  std::cin >> number;
  for (int i = 0; i < number; i++) {
    double price;

    std::cin >> price;
    std::cout << std::fixed << std::setprecision(2) << "$" << price * 0.8 << std::endl;
  }
}
