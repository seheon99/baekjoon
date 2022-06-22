#include <algorithm>
#include <deque>
#include <iostream>

int main(void) {
  std::deque<int> rotation;
  int rotation_size;
  int number_of_targets;
  int answer = 0;

  std::cin >> rotation_size >> number_of_targets;
  rotation.resize(rotation_size);
  for (int i = 0; i < rotation_size; i++) {
    rotation[i] = i + 1;
  }

  for (int i = 0; i < number_of_targets; i++) {
    int target;
    std::cin >> target;

    auto target_iter = std::find(rotation.begin(), rotation.end(), target);
    int length = target_iter - rotation.begin();

    if (length <= rotation.size() / 2) {
      answer += length;
      for (int k = 0; k < length; k++) {
        rotation.push_back(rotation.front());
        rotation.pop_front();
      }
    } else {
      answer += rotation.size() - length;
      for (int k = 0; k < rotation.size() - length; k++) {
        rotation.push_front(rotation.back());
        rotation.pop_back();
      }
    }
    rotation.pop_front();
  }
  std::cout << answer;
  return 0;
}
