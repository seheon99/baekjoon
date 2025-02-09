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

  std::vector<int> lis(n_numbers);

  for (int i = 0; i < n_numbers; i++) {
    lis[i] = numbers[i];
  }

  for (int i = 1; i < n_numbers; i++) {
    for (int j = 0; j < i; j++) {
      if (numbers[j] < numbers[i]) {
        lis[i] = std::max(lis[i], lis[j] + numbers[i]);
      }
    }
  }

  std::cout << *std::max_element(lis.begin(), lis.end()) << std::endl;

  return 0;
}