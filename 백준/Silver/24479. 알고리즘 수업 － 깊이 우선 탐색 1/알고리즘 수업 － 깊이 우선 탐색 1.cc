#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, r;
    std::cin >> n >> m >> r;

    std::vector<int> edges[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        std::sort(edges[i].begin(), edges[i].end(),
                  [](int a, int b) -> int { return a > b; });
    }

    int visited[n + 1] = {0};
    int count = 1;
    std::stack<int> work;
    work.push(r);
    while (!work.empty()) {
        int u = work.top();
        work.pop();
        if (visited[u] > 0) {
            continue;
        }

        visited[u] = count++;
        for (int i = 0; i < edges[u].size(); i++) {
            int v = edges[u][i];

            if (visited[v] == 0) {
                work.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << visited[i] << '\n';
    }

    return 0;
}
