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

  std::vector<int> lis(n_numbers, 1);
  std::vector<int> prev(n_numbers, -1);

  for (int i = 1; i < n_numbers; i++) {
    for (int j = 0; j < i; j++) {
      if (numbers[j] < numbers[i] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
        prev[i] = j;
      }
    }
  }

  int max_index = 0;
  for (int i = 1; i < n_numbers; i++) {
    if (lis[i] > lis[max_index]) {
      max_index = i;
    }
  }

  std::vector<int> answer;
  answer.reserve(lis[max_index]);

  int i = max_index;
  while (i != -1) {
    answer.push_back(numbers[i]);
    i = prev[i];
  }
  std::reverse(answer.begin(), answer.end());

  std::cout << lis[max_index] << '\n';
  for (auto number : answer) {
    std::cout << number << ' ';
  }
  std::cout << std::endl;

  return 0;
}