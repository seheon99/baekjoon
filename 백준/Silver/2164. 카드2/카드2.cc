#include <iostream>
#include <queue>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::queue<int> cards;
  int number_of_cards;

  std::cin >> number_of_cards;
  for (int i = 1; i <= number_of_cards; i++) {
    cards.push(i);
  }

  while (cards.size() > 1) {
    cards.pop();
    cards.push(cards.front());
    cards.pop();
  }

  std::cout << cards.front() << std::endl;
  return 0;
}
