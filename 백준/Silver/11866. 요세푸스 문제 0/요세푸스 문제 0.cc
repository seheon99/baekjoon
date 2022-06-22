#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::queue<int> josephus_queue;
  std::vector<int> answer;
  int N, K;

  std::cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    josephus_queue.push(i);
  }
  answer.reserve(N);

  while (josephus_queue.size() > 0) {
    for (int i = 0; i < K - 1; i++) {
      josephus_queue.push(josephus_queue.front());
      josephus_queue.pop();
    }
    answer.push_back(josephus_queue.front());
    josephus_queue.pop();
  }
  std::cout << "<";
  for (int i = 0; i < N; i++) {
    std::cout << answer[i];
    if (i != N - 1) {
      std::cout << ", ";
    }
  }
  std::cout << ">";
  return 0;
}
