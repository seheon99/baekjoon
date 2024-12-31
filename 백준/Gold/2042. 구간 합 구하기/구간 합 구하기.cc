#include <cmath>
#include <iostream>
#include <vector>

using number = long long;

std::vector<number> numbers;
std::vector<number> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start - 1];
  } else {
    int mid = (start + end) / 2;
    init(2 * node, start, mid);
    init(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void init() { return init(1, 1, numbers.size()); }

number query(int node, int from, int to, int start, int end) {
  if (to < start || end < from) {
    return 0;
  } else if (from <= start && end <= to) {
    return tree[node];
  } else {
    int mid = (start + end) / 2;
    return query(2 * node, from, to, start, mid) +
           query(2 * node + 1, from, to, mid + 1, end);
  }
}

number query(int from, int to) { return query(1, from, to, 1, numbers.size()); }

void update(int target, number diff, int node, int start, int end) {
  tree[node] += diff;

  if (start == end) {
    return;
  }

  int mid = (start + end) / 2;
  if (target <= mid) {
    update(target, diff, 2 * node, start, mid);
  } else {
    update(target, diff, 2 * node + 1, mid + 1, end);
  }
}

void update(int target, number diff) {
  return update(target, diff, 1, 1, numbers.size());
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;

  numbers = std::vector<number>(n);
  for (auto& number : numbers) {
    std::cin >> number;
  }

  tree = std::vector<number>(1 << ((int)ceil(log2(n)) + 1));
  init();

  int count = 0;
  while (count < k) {
    number a, b, c;
    std::cin >> a >> b >> c;

    if (a == 1) {
      update(b, c - numbers[b - 1]);
      numbers[b - 1] = c;
    } else {
      std::cout << query(b, c) << '\n';
      count++;
    }
  }

  return 0;
}