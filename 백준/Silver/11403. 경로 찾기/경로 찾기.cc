#include <iostream>
#include <stack>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    bool edges[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> edges[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        std::stack<int> work;
        bool visited[n] = {};

        for (int j = 0; j < n; j++) {
            if (edges[i][j]) {
                visited[j] = true;
                work.push(j);
            }
        }

        while (!work.empty()) {
            int ni = work.top();
            work.pop();

            for (int j = 0; j < n; j++) {
                if (visited[j] == false && edges[ni][j]) {
                    visited[j] = true;
                    work.push(j);
                    edges[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << edges[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
