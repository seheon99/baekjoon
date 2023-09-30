#include <iostream>

const int N_MAX = 1001;
const long long COST_MAX = (long long)100000 * 100000 + 1;

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

    int start, end;
    std::cin >> start >> end;

    bool visited[N_MAX] = {false};

    while (true) {
        int tp = -1;
        long long cost = COST_MAX;

        for (int i = 1; i <= n_city; i++) {
            if (i == start || visited[i]) {
                continue;
            }
            if (costs[start][i] < cost) {
                tp = i;
                cost = costs[start][i];
            }
        }

        if (tp == -1) {
            break;
        }
        visited[tp] = true;

        for (int ep = 1; ep <= n_city; ep++) {
            if (ep == start || ep == tp || costs[tp][ep] == COST_MAX) {
                continue;
            }
            costs[start][ep] =
                std::min(costs[start][ep], costs[start][tp] + costs[tp][ep]);
        }
    }

    std::cout << costs[start][end];

    return 0;
}
