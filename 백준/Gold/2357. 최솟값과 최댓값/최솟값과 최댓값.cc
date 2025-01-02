#include <cmath>
#include <iostream>
#include <vector>

using tree_t = std::vector<int>;

std::vector<int> numbers;
tree_t min_tree;
tree_t max_tree;

template <typename Compare>
void init(tree_t& tree, Compare compare, int node, int start, int end) {
  if (start == end) {
    tree[node] = numbers[start];
  } else {
    int mid = (start + end) / 2;
    init(tree, compare, 2 * node, start, mid);
    init(tree, compare, 2 * node + 1, mid + 1, end);
    tree[node] = compare(tree[2 * node], tree[2 * node + 1]);
  }
}

void min_init(tree_t& tree) {
  return init(
      tree, [](int a, int b) -> int { return std::min(a, b); }, 1, 0,
      numbers.size() - 1);
}

void max_init(tree_t& tree) {
  return init(
      tree, [](int a, int b) -> int { return std::max(a, b); }, 1, 0,
      numbers.size() - 1);
}

template <typename Compare>
int query(tree_t& tree, Compare compare, int fallback, int node, int from,
          int to, int start, int end) {
  if (from > end || to < start) {
    return fallback;
  }
  if (from <= start && end <= to) {
    return tree[node];
  }

  int mid = (start + end) / 2;
  int left = query(tree, compare, fallback, 2 * node, from, to, start, mid);
  int right =
      query(tree, compare, fallback, 2 * node + 1, from, to, mid + 1, end);
  return compare(left, right);
}

int min_query(tree_t& tree, int from, int to) {
  return query(
      tree, [](int a, int b) -> int { return std::min(a, b); }, INT32_MAX, 1,
      from, to, 0, numbers.size() - 1);
}

int max_query(tree_t& tree, int from, int to) {
  return query(
      tree, [](int a, int b) -> int { return std::max(a, b); }, INT32_MIN, 1,
      from, to, 0, numbers.size() - 1);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_numbers, n_queries;
  std::cin >> n_numbers >> n_queries;

  numbers = std::vector<int>(n_numbers);
  for (auto& number : numbers) {
    std::cin >> number;
  }

  min_tree = tree_t(1 << ((int)ceil(log2(n_numbers)) + 1));
  min_init(min_tree);
  max_tree = tree_t(1 << ((int)ceil(log2(n_numbers)) + 1));
  max_init(max_tree);

  for (int i = 0; i < n_queries; i++) {
    int from, to;
    std::cin >> from >> to;
    std::cout << min_query(min_tree, from - 1, to - 1) << ' '
              << max_query(max_tree, from - 1, to - 1) << '\n';
  }

  return 0;
}