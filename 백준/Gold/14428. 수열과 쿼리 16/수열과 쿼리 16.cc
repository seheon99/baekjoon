#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> numbers;
std::vector<int> tree;

void init(int node, int start, int end) {
  if (start == end) {
    tree[node] = start;
    return;
  }

  int mid = (start + end) / 2;
  init(2 * node, start, mid);
  init(2 * node + 1, mid + 1, end);
  tree[node] = numbers[tree[2 * node]] <= numbers[tree[2 * node + 1]]
                   ? tree[2 * node]
                   : tree[2 * node + 1];
  return;
}

void init() { init(1, 0, numbers.size() - 1); }

void update(int node, int target, int start, int end) {
  if (target < start || target > end) {
    return;
  }
  if (start == end) {
    return;
  }

  int mid = (start + end) / 2;
  update(2 * node, target, start, mid);
  update(2 * node + 1, target, mid + 1, end);
  tree[node] = numbers[tree[2 * node]] <= numbers[tree[2 * node + 1]]
                   ? tree[2 * node]
                   : tree[2 * node + 1];
}

void update(int target) { update(1, target, 0, numbers.size() - 1); }

int query(int node, int from, int to, int start, int end) {
  if (from > end || to < start) {
    return -1;
  }
  if (from <= start && to >= end) {
    return tree[node];
  }

  int mid = (start + end) / 2;
  int left = query(2 * node, from, to, start, mid);
  int right = query(2 * node + 1, from, to, mid + 1, end);
  return left == -1                        ? right
         : right == -1                     ? left
         : numbers[left] <= numbers[right] ? left
                                           : right;
}

int query(int from, int to) {
  return query(1, from, to, 0, numbers.size() - 1);
}

int main() {
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

  int command, a, b;
  for (int i = 0; i < n_queries; i++) {
    std::cin >> command >> a >> b;

    if (command == 1) {
      numbers[a - 1] = b;
      update(a - 1);
    } else if (command == 2) {
      std::cout << query(a - 1, b - 1) + 1 << '\n';
    }
  }

  return 0;
}