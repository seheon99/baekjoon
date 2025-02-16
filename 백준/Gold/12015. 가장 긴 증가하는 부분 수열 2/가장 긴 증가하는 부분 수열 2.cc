#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 2'147'483'647;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> sequence(n);
  for (int& number : sequence) {
    std::cin >> number;
  }

  std::vector<int> dp;
  dp.reserve(n);
  std::vector<int> index(n), trace(n, -1);

  for (int i = 0; i < n; ++i) {
    int number = sequence[i];
    int left = 0, right = dp.size();

    while (left < right) {
      int mid = (left + right) / 2;
      if (dp[mid] < number) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left == dp.size()) {
      dp.push_back(number);
    } else {
      dp[left] = number;
    }

    index[left] = i;
    trace[i] = (left > 0) ? index[left - 1] : -1;
  }

  std::cout << dp.size() << '\n';

  return 0;
}
