// 10999

#include <iostream>

using number = long long;

static const int N_MAX = 1'000'000;

static int n_numbers;
static number numbers[N_MAX];
static number tree[4 * N_MAX];
static number lazy[4 * N_MAX];

static void initialize(int node, int left, int right) {
  if (left == right) {
    tree[node] = numbers[left];
  } else {
    int mid = (left + right) / 2;
    initialize(node * 2, left, mid);
    initialize(node * 2 + 1, mid + 1, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
}

static void initialize() { return initialize(1, 0, n_numbers - 1); }

static void propagate(int node, int left, int right) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node] * (right - left + 1);
    if (left != right) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

static number query(int from, int to, int node, int left, int right) {
  if (to < left || from > right) {
    return 0;
  }

  propagate(node, left, right);

  if (left >= from && right <= to) {
    return tree[node];
  }

  int mid = (left + right) / 2;
  number l = query(from, to, node * 2, left, mid);
  number r = query(from, to, node * 2 + 1, mid + 1, right);
  return l + r;
}

static number query(int from, int to) {
  return query(from, to, 1, 0, n_numbers - 1);
}

static void update(int from, int to, number value, int node, int left,
                   int right) {
  propagate(node, left, right);
  if (right < from || left > to) {
    return;
  }

  if (from <= left && to >= right) {
    tree[node] += (right - left + 1) * value;
    if (left != right) {
      lazy[node * 2] += value;
      lazy[node * 2 + 1] += value;
    }
    return;
  }

  int mid = (left + right) / 2;
  update(from, to, value, node * 2, left, mid);
  update(from, to, value, node * 2 + 1, mid + 1, right);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

static void update(int from, int to, number value) {
  return update(from, to, value, 1, 0, n_numbers - 1);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_updates, n_queries;

  std::cin >> n_numbers;
  std::cin >> n_updates >> n_queries;

  for (int i = 0; i < n_numbers; i++) {
    std::cin >> numbers[i];
  }

  initialize();

  while (n_updates + n_queries > 0) {
    int type, from, to;
    std::cin >> type;

    if (type == 1) {
      number value;

      std::cin >> from >> to >> value;
      update(from - 1, to - 1, value);
      --n_updates;
    } else if (type == 2) {
      std::cin >> from >> to;
      std::cout << query(from - 1, to - 1) << '\n';
      --n_queries;
    }
  }

  return 0;
}