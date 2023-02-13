#include <iostream>

static int buffer[8];
static int n, m;

static void permutation(int i) {
    if (i == m) {
        for (int k = 0; k < m; k++) {
            std::cout << buffer[k] << ' ';
        }
        std::cout << '\n';
    } else {
        for (buffer[i] = buffer[i - 1]; buffer[i] <= n; buffer[i]++) {
            permutation(i + 1);
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    for (buffer[0] = 1; buffer[0] <= n; buffer[0]++) {
        permutation(1);
    }
    return 0;
}
