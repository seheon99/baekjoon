#include <iostream>
#include <stack>
#include <string>

int main(void) {
  while (true) {
    std::string line;
    std::stack<char> world;
    bool balance = true;

    std::getline(std::cin, line);
    if (line == ".") {
      break;
    }
    for (auto iter = line.begin(); iter != line.end(); iter++) {
      if (*iter == '(' || *iter == '[') {
        world.push(*iter);
      } else if (*iter == ')' || *iter == ']') {
        if (world.size() == 0) {
          balance = false;
          break;
        } else if ((*iter == ')' && world.top() != '(') ||
                   (*iter == ']' && world.top() != '[')) {
          balance = false;
          break;
        } else if ((*iter == ')' && world.top() == '(') ||
                   (*iter == ']' && world.top() == '[')) {
          world.pop();
        }
      }
    }
    if (world.size() > 0 || balance == false) {
      std::cout << "no\n";
    } else {
      std::cout << "yes\n";
    }
  }
  return 0;
}
