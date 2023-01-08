#include <iostream>

int tiling(int n) {
    static int cache[1001] = {0, 1, 2};

    if (cache[n] == 0) {
        cache[n] = (tiling(n - 1) + tiling(n - 2)) % 10007;
    }

    return cache[n];
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << tiling(n);
    return 0;
}
