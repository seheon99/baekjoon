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

  std::vector<int> lis(n_numbers, 1);
  std::vector<int> lds(n_numbers, 1);

  for (int i = 1; i < n_numbers; i++) {
    for (int j = 0; j < i; j++) {
      if (numbers[j] < numbers[i]) {
        lis[i] = std::max(lis[i], lis[j] + 1);
      }
      if (numbers[n_numbers - 1 - i] > numbers[n_numbers - 1 - j]) {
        lds[n_numbers - 1 - i] =
            std::max(lds[n_numbers - 1 - i], lds[n_numbers - 1 - j] + 1);
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < n_numbers; i++) {
    answer = std::max(answer, lis[i] + lds[i] - 1);
  }

  std::cout << answer << std::endl;

  return 0;
}