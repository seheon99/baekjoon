#include <iostream>
#include <vector>

const int MAX_QUALITY = 1'000'000;

std::vector<int> tree = std::vector<int>(4 * MAX_QUALITY);

int query_nth_candy(int n, int node, int left, int right) {
  if (left == right) {
    return left;
  }

  int mid = (left + right) / 2;

  if (n > tree[node * 2]) {
    return query_nth_candy(n - tree[node * 2], node * 2 + 1, mid + 1, right);
  } else {
    return query_nth_candy(n, node * 2, left, mid);
  }
}

int query_nth_candy(int n) { return query_nth_candy(n, 1, 1, MAX_QUALITY); }

void update(int quality, int n_candies, int node, int left, int right) {
  if (quality == left && quality == right) {
    tree[node] += n_candies;
    return;
  }

  int mid = (left + right) / 2;

  if (quality <= mid) {
    update(quality, n_candies, node * 2, left, mid);
  } else {
    update(quality, n_candies, node * 2 + 1, mid + 1, right);
  }

  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int quality, int n_candies) {
  update(quality, n_candies, 1, 1, MAX_QUALITY);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_queries;
  std::cin >> n_queries;

  for (int i = 0; i < n_queries; i++) {
    int cmd;
    std::cin >> cmd;

    if (cmd == 1) {
      int rank;
      std::cin >> rank;

      int quality = query_nth_candy(rank);
      update(quality, -1);
      std::cout << quality << '\n';
    } else if (cmd == 2) {
      int quality, n_candies;
      std::cin >> quality >> n_candies;
      update(quality, n_candies);
    }
  }

  return 0;
}