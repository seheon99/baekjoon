#include <iostream>
#include <vector>

using number = long long;

int n_numbers;
std::vector<number> tree;

void modify(int x, int value, int node, int left, int right) {
  if (x == left && x == right) {
    tree[node] = value;
    return;
  }

  int mid = (left + right) / 2;
  if (x <= mid) {
    modify(x, value, node * 2, left, mid);
  } else {
    modify(x, value, node * 2 + 1, mid + 1, right);
  }
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
  return;
}

void modify(int x, int value) { return modify(x, value, 1, 0, n_numbers - 1); }

number sum(int from, int to, int node, int left, int right) {
  if (from <= left && to >= right) {
    return tree[node];
  }

  if (from > right || to < left) {
    return 0;
  }

  int mid = (left + right) / 2;
  return sum(from, to, node * 2, left, mid) +
         sum(from, to, node * 2 + 1, mid + 1, right);
}

number sum(int from, int to) { return sum(from, to, 1, 0, n_numbers - 1); }

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_queries;
  std::cin >> n_numbers >> n_queries;

  tree.resize(n_numbers * 4);

  for (int i = 0; i < n_queries; i++) {
    int query_type, param_1, param_2;
    std::cin >> query_type >> param_1 >> param_2;

    if (query_type == 0) {
      if (param_1 > param_2) {
        std::swap(param_1, param_2);
      }
      std::cout << sum(param_1 - 1, param_2 - 1) << '\n';
    } else {
      modify(param_1 - 1, param_2);
    }
  }

  return 0;
}