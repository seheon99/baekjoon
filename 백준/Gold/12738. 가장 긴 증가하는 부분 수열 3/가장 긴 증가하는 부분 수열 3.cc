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

  for (int const number : sequence) {
    if (dp.empty() || dp.back() < number) {
      dp.push_back(number);
      continue;
    }

    int left = 0;
    int right = dp.size();
    while (left < right) {
      int mid = (left + right) / 2;
      if (dp[mid] == number) {
        left = mid;
        break;
      } else if (dp[mid] < number) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    dp[left] = number;
  }

  std::cout << dp.size() << '\n';
  return 0;
}
