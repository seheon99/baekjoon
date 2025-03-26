#include <iostream>
#include <stack>
#include <vector>

static const int N_MAX = 32'000;

static std::vector<int> adjs[N_MAX + 1];
static std::vector<int> answer;
static bool visited[N_MAX + 1];

static void dfs(int index) {
  for (auto adj : adjs[index]) {
    if (!visited[adj]) {
      visited[adj] = true;
      dfs(adj);
    }
  }

  answer.push_back(index);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n_vertices, n_edges;
  std::cin >> n_vertices >> n_edges;

  answer.reserve(n_vertices);

  for (int i = 0; i < n_edges; i++) {
    int from, to;
    std::cin >> from >> to;
    adjs[to].push_back(from);
  }

  for (int i = 1; i <= n_vertices; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    dfs(i);
  }

  for (auto n : answer) {
    std::cout << n << ' ';
  }
  std::cout << '\n';

  return 0;
}