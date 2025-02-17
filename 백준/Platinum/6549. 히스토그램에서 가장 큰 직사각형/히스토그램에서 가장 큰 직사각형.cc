#include <iostream>

static const int N_MAX = 100'000;
static const int HEIGHT_MAX = 1'000'000'000;

// static const long ANSWER_MAX = 100'000'000'000'000;

using number = long;

static int n;
static int heights[N_MAX];
static int segtree[4 * N_MAX];

int min_height_index(int index_a, int index_b) {
  if (index_a == -1) {
    return index_b;
  } else if (index_b == -1) {
    return index_a;
  } else {
    return heights[index_a] <= heights[index_b] ? index_a : index_b;
  }
}

void init(int index, int left, int right) {
  if (left == right) {
    segtree[index] = left;
    return;
  }

  int mid = (left + right) / 2;
  init(index * 2, left, mid);
  init(index * 2 + 1, mid + 1, right);
  segtree[index] = min_height_index(segtree[index * 2], segtree[index * 2 + 1]);
  return;
}

void init() { return init(1, 0, n - 1); }

int query(int index, int left, int right, int from, int to) {
  if (right < from || left > to) {
    return -1;
  } else if (left >= from && right <= to) {
    return segtree[index];
  }

  int mid = (left + right) / 2;
  int leftq = query(index * 2, left, mid, from, to);
  int rightq = query(index * 2 + 1, mid + 1, right, from, to);
  return min_height_index(leftq, rightq);
}

int query(int from, int to) { return query(1, 0, n - 1, from, to); }

number calculate(int from, int to) {
  if (from > to) {
    return 0;
  } else if (from == to) {
    return heights[from];
  }

  int min_height_index = query(from, to);

  number full = (number)heights[min_height_index] * (to - from + 1);
  number left = calculate(from, min_height_index - 1);
  number right = calculate(min_height_index + 1, to);
  return std::max(full, left < right ? right : left);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      std::cin >> heights[i];
    }

    init();
    std::cout << calculate(0, n - 1) << '\n';
  }

  return 0;
}