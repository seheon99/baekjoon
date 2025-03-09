#include <deque>
#include <iostream>
#include <vector>

using number = int;
using package = std::pair<int, number>;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int length, sight;
  std::vector<number> lights;
  std::deque<package> window;

  std::cin >> length >> sight;
  lights.resize(length);
  for (auto& light : lights) {
    std::cin >> light;
  }

  for (int i = 0; i < length; i++) {
    if (!window.empty() && window.front().first < i - (sight * 2 - 1) + 1) {
      window.pop_front();
    }
    while (!window.empty() && window.back().second <= lights[i]) {
      window.pop_back();
    }
    window.push_back({i, lights[i]});
    if (i >= sight * 2 - 1 - 1) {
      std::cout << window.front().second << ' ';
    }
  }

  return 0;
}