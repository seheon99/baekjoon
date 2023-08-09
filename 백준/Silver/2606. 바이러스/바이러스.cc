#include <iostream>
#include <vector>

int main(void) {
    const int N_MAX = 100;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> edges[N_MAX + 1];
    for (int i = 0; i <= N_MAX; i++) {
        edges[i].reserve(N_MAX);
    }

    int n_edges;
    std::cin >> n_edges;
    for (int i = 0; i < n_edges; i++) {
        int a, b;
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bool affected[N_MAX + 1] = {
        true,
        true,
    };
    std::vector<int> queue = {1};
    queue.reserve(N_MAX);

    for (int i = 0; i < queue.size(); i++) {
        int from = queue[i];
        for (int to : edges[from]) {
            if (affected[to] == false) {
                affected[to] = true;
                queue.push_back(to);
            }
        }
    }

    std::cout << queue.size() - 1;
    return 0;
}
