#include <iostream>

static int countSubsequence(int n, int s, int *nums, int index) {
  static bool check[20];
  static int sum;
  int ret = 0;

  check[index] = true;
  sum += nums[index];
  if (sum == s) {
    ++ret;
  }
  for (int i = index; i < n; ++i) {
    if (check[i] == false) {
      ret += countSubsequence(n, s, nums, i);
    }
  }
  check[index] = false;
  sum -= nums[index];
  return ret;
}

int main(void) {
  int n, s, nums[20], ret = 0;

  std::cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }
  for (int i = 0; i < n; ++i) {
    ret += countSubsequence(n, s, nums, i);
  }
  std::cout << ret;
  return 0;
}
