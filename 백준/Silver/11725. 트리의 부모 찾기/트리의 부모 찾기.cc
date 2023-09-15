#include <iostream>
#include <queue>
#include <vector>

const int N_MAX = 100001;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> edges[N_MAX];

    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int parent[N_MAX] = {0, -1};
    std::queue<int> queue;
    queue.push(1);
    while (queue.empty() == false) {
        int node = queue.front();
        queue.pop();
        for (auto next : edges[node]) {
            if (parent[next] == 0) {
                parent[next] = node;
                queue.push(next);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        std::cout << parent[i] << '\n';
    }
    return 0;
}
