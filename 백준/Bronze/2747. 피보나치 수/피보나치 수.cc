#include <iostream>

static int fibonacci(int n) {
    static int cache[50] = {0, 1};

    if (n > 1 && cache[n] == 0) {
        cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return cache[n];
}

int main(void) {
    int n;
    std::cin >> n;
    std::cout << fibonacci(n);
    return 0;
}