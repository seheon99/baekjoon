#include <iostream>

const int N_MAX = 101;
const long long COST_MAX = INT64_MAX;

int main(void) {
    int n_city, n_bus;
    std::cin >> n_city >> n_bus;

    long long costs[N_MAX][N_MAX];
    for (int sp = 1; sp <= n_city; sp++) {
        for (int ep = 1; ep <= n_city; ep++) {
            if (sp == ep) {
                costs[sp][ep] = 0;
            } else {
                costs[sp][ep] = COST_MAX;
            }
        }
    }

    for (int i = 0; i < n_bus; i++) {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        costs[start][end] = std::min(costs[start][end], (long long)cost);
    }

    for (int sp = 1; sp <= n_city; sp++) {
        bool visited[N_MAX] = {false};

        while (true) {
            int tp = -1;
            long long cost = COST_MAX;

            for (int i = 1; i <= n_city; i++) {
                if (i == sp || visited[i]) {
                    continue;
                }
                if (costs[sp][i] < cost) {
                    tp = i;
                    cost = costs[sp][i];
                }
            }

            if (tp == -1) {
                break;
            }
            visited[tp] = true;

            for (int ep = 1; ep <= n_city; ep++) {
                if (ep == sp || ep == tp || costs[tp][ep] == COST_MAX) {
                    continue;
                }
                costs[sp][ep] =
                    std::min(costs[sp][ep], costs[sp][tp] + costs[tp][ep]);
            }
        }
    }

    for (int sp = 1; sp <= n_city; sp++) {
        for (int ep = 1; ep <= n_city; ep++) {
            std::cout << (costs[sp][ep] == COST_MAX ? 0 : costs[sp][ep]) << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
