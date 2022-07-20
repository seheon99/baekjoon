#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

static const int VERTEX_MAX = 1000;

static void print_dfs_path(std::vector<int> *edges, int current_point);
static void print_bfs_path(std::vector<int> *edges, int start_point);

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int number_of_vertex;
  int number_of_edges;
  int start_point;
  std::vector<int> edges[VERTEX_MAX + 1];

  std::cin >> number_of_vertex >> number_of_edges >> start_point;
  for (int i = 0; i < number_of_edges; i++) {
    int u, v;

    std::cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 1; i <= number_of_vertex; i++) {
    std::sort(edges[i].begin(), edges[i].end());
  }

  print_dfs_path(edges, start_point);
  std::cout << "\n";
  print_bfs_path(edges, start_point);
  std::cout << std::endl;
  return 0;
}

static void print_dfs_path(std::vector<int> *edges, int current_point) {
  static bool visited[VERTEX_MAX + 1];

  if (visited[current_point] == true) {
    return;
  } else {
    visited[current_point] = true;
    std::cout << current_point << " ";
  }

  for (auto next_point : edges[current_point]) {
    if (visited[next_point] == false) {
      print_dfs_path(edges, next_point);
    }
  }

  return;
}

static void print_bfs_path(std::vector<int> *edges, int start_point) {
  static std::queue<int> bfs_buffer;
  static bool visited[VERTEX_MAX + 1];

  if (bfs_buffer.empty()) {
    if (start_point > 0) {
      bfs_buffer.push(start_point);
    } else {
      return;
    }
  }

  int current_point;

  current_point = bfs_buffer.front();
  bfs_buffer.pop();
  if (visited[current_point] == true) {
    return print_bfs_path(edges, 0);
  } else {
    visited[current_point] = true;
    std::cout << current_point << " ";
  }

  for (auto next_point : edges[current_point]) {
    if (visited[next_point] == false) {
      bfs_buffer.push(next_point);
    }
  }

  return print_bfs_path(edges, 0);
}
