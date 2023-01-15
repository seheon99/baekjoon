#include <iostream>

uint64_t padovan(int n) {
    static uint64_t cache[101] = {0, 1, 1, 1};

    if (cache[n] == 0) {
        cache[n] = padovan(n - 2) + padovan(n - 3);
    }
    return cache[n];
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::cout << padovan(n) << '\n';
    }
    return 0;
}
