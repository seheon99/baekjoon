#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int numbers[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        std::cin >> numbers[i];
        numbers[i] += numbers[i - 1];
    }

    for (int k = 0; k < m; k++) {
        int i, j;
        std::cin >> i >> j;
        std::cout << numbers[j] - numbers[i - 1] << '\n';
    }
    return 0;
}
