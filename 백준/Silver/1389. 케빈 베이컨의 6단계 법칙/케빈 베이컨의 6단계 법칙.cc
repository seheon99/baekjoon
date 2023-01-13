#include <iostream>
#include <queue>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> relation[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        relation[u].push_back(v);
        relation[v].push_back(u);
    }

    int kevin_sum[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        int visited[n + 1] = {0};

        std::queue<int> work;
        for (int j = 0; j < relation[i].size(); j++) {
            int n = relation[i][j];

            work.push(n);
            visited[n] = 1;
        }

        while (!work.empty()) {
            int n = work.front();
            work.pop();

            for (int k = 0; k < relation[n].size(); k++) {
                int m = relation[n][k];

                if (visited[m] == 0) {
                    visited[m] = visited[n] + 1;
                    work.push(m);
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            kevin_sum[i] += visited[j];
        }
    }

    int min = 1;
    for (int i = 1; i <= n; i++) {
        if (kevin_sum[i] < kevin_sum[min]) {
            min = i;
        }
    }
    std::cout << min;
    return 0;
}
