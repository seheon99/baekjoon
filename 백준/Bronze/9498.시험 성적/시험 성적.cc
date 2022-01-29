#include <iostream>

int main(void) {
  int score;

  std::cin >> score;
  if (score <= 100 && score >= 90) {
    std::cout << "A";
  } else if (score < 90 && score >= 80) {
    std::cout << "B";
  } else if (score < 80 && score >= 70) {
    std::cout << "C";
  } else if (score < 70 && score >= 60) {
    std::cout << "D";
  } else {
    std::cout << "F";
  }
  return 0;
}
