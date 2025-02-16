#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> numbers;
std::vector<int> tree;

using std::min;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start];
  } else {
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }
}

void init() { init(1, 0, numbers.size() - 1); }

void update(int node, int x, int start, int end) {
  if (x < start || x > end) {
    return;
  }

  if (x == start && x == end) {
    tree[node] = numbers[x];
    return;
  }

  int mid = (start + end) / 2;
  update(node * 2, x, start, mid);
  update(node * 2 + 1, x, mid + 1, end);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void update(int x, int value) {
  numbers[x] = value;
  update(1, x, 0, numbers.size() - 1);
}

int query(int node, int from, int to, int start, int end) {
  if (to < start || from > end) {
    return INT32_MAX;
  }

  if (from <= start && to >= end) {
    return tree[node];
  }

  int mid = (start + end) / 2;
  int left = query(node * 2, from, to, start, mid);
  int right = query(node * 2 + 1, from, to, mid + 1, end);
  return min(left, right);
}

int query(int from, int to) {
  return query(1, from, to, 0, numbers.size() - 1);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_numbers;
  std::cin >> n_numbers;

  numbers.resize(n_numbers);
  for (auto& number : numbers) {
    std::cin >> number;
  }

  tree.resize(1 << (1 + (int)ceil(log2(n_numbers))));
  init();

  int n_queries;
  std::cin >> n_queries;
  for (int i = 0; i < n_queries; i++) {
    int cmd;
    std::cin >> cmd;

    if (cmd == 1) {
      int x, value;
      std::cin >> x >> value;
      update(x - 1, value);
    } else if (cmd == 2) {
      int from, to;
      std::cin >> from >> to;
      std::cout << query(from - 1, to - 1) << '\n';
    }
  }

  return 0;
}