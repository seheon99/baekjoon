#include <cmath>
#include <iostream>
#include <vector>

using number = long long;

std::vector<int> numbers;
std::vector<int> tree;

int calculate(int a, int b) { return ((long long)a * b) % 1000000007; }

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start];
    return;
  }

  int mid = (start + end) / 2;
  init(2 * node, start, mid);
  init(2 * node + 1, mid + 1, end);
  tree[node] = calculate(tree[2 * node], tree[2 * node + 1]);
}

void init() { init(1, 0, numbers.size() - 1); }

void update(int node, int x, int value, int start, int end) {
  if (x < start || x > end) {
    return;
  }

  if (start == end) {
    tree[node] = value;
    return;
  }

  int mid = (start + end) / 2;
  update(2 * node, x, value, start, mid);
  update(2 * node + 1, x, value, mid + 1, end);
  tree[node] = calculate(tree[2 * node], tree[2 * node + 1]);
}

void update(int x, int value) { update(1, x, value, 0, numbers.size() - 1); }

int query(int node, int from, int to, int start, int end) {
  if (from > end || to < start) {
    return 1;
  }
  if (from <= start && to >= end) {
    return tree[node];
  }

  int mid = (start + end) / 2;
  int left = query(2 * node, from, to, start, mid);
  int right = query(2 * node + 1, from, to, mid + 1, end);
  return calculate(left, right);
}

int query(int from, int to) {
  return query(1, from, to, 0, numbers.size() - 1);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_numbers, n_updates, n_queries;
  std::cin >> n_numbers >> n_updates >> n_queries;

  numbers.resize(n_numbers);
  for (auto& number : numbers) {
    std::cin >> number;
  }

  tree.resize(1 << (1 + (int)ceil(log2(n_numbers))));
  init();

  int command, b, c;
  int count = 0;
  while (count < n_queries) {
    std::cin >> command >> b >> c;
    if (command == 1) {
      update(b - 1, c);
    } else if (command == 2) {
      std::cout << query(b - 1, c - 1) << '\n';
      count++;
    }
  }

  return 0;
}