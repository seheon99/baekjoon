#include <deque>
#include <iostream>
#include <limits>
#include <vector>

using number = int;

struct data {
  number value;
  int index;
};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_numbers, length;
  std::vector<number> numbers;
  std::deque<data> window;

  std::cin >> n_numbers >> length;
  numbers.resize(n_numbers);
  for (auto& n : numbers) {
    std::cin >> n;
  }

  for (int i = 0; i < n_numbers; i++) {
    if (!window.empty() && window.front().index < i - length + 1) {
      window.pop_front();
    }
    while (!window.empty() && window.back().value >= numbers[i]) {
      window.pop_back();
    }
    window.push_back({numbers[i], i});
    std::cout << window.front().value << ' ';
  }

  return 0;
}