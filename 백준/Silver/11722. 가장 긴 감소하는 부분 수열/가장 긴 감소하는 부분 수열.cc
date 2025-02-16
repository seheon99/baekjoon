#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_numbers;
  std::vector<int> numbers;

  std::cin >> n_numbers;
  numbers.resize(n_numbers);
  for (auto& number : numbers) {
    std::cin >> number;
  }

  std::vector<int> lds(n_numbers, 1);

  for (int i = 1; i < n_numbers; i++) {
    for (int j = 0; j < i; j++) {
      if (numbers[j] > numbers[i]) {
        lds[i] = std::max(lds[i], lds[j] + 1);
      }
    }
  }

  std::cout << *std::max_element(lds.begin(), lds.end()) << std::endl;

  return 0;
}