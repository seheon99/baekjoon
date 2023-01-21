#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    int count[n] = {1, 3};
    for (int i = 2; i < n; i++) {
        count[i] = (count[i - 1] + 2 * count[i - 2]) % 10007;
    }
    std::cout << count[n - 1];
    return 0;
}
