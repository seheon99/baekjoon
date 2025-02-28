#include <iostream>

int main() {
  int n_coins, target;
  std::cin >> n_coins >> target;

  int coins[100];
  for (int i = 0; i < n_coins; i++) {
    std::cin >> coins[i];
  }

  int cache[10001] = {1};
  for (int i = 0; i < n_coins; i++) {
    for (int value = 1; value <= target; value++) {
      if (coins[i] <= value) {
        cache[value] += cache[value - coins[i]];
      }
    }
  }

  std::cout << cache[target];

  return 0;
}