#include <iostream>
#include <string>

static const int MAX_LENGTH = 1'000'000;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string text;
  std::string pattern;

  std::getline(std::cin, text);
  std::getline(std::cin, pattern);

  int pi_pattern[MAX_LENGTH] = {0};
  for (int i = 1; i < pattern.length(); i++) {
    int k = pi_pattern[i - 1];
    while (k > 0) {
      if (pattern[i] == pattern[k]) {
        pi_pattern[i] = k + 1;
        break;
      }
      k = pi_pattern[k - 1];
    }
    if (k == 0) {
      pi_pattern[i] = pattern[i] == pattern[k] ? 1 : 0;
    }
  }

  int count = 0;
  int answer[MAX_LENGTH];

  int pi_text[MAX_LENGTH] = {};
  for (int i = 0; i < text.length(); i++) {
    int k = i > 0 ? pi_text[i - 1] : 0;
    while (k > 0) {
      if (k < pattern.length() && text[i] == pattern[k]) {
        pi_text[i] = k + 1;
        break;
      }
      k = pi_pattern[k - 1];
    }
    if (k == 0) {
      pi_text[i] = text[i] == pattern[k] ? 1 : 0;
    }

    if (pi_text[i] == pattern.length()) {
      answer[count++] = i + 1 - (pattern.length() - 1);
    }
  }

  std::cout << count << '\n';
  for (int i = 0; i < count; i++) {
    std::cout << answer[i] << ' ';
  }

  return 0;
}