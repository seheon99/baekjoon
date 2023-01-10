#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    int two[501] = {0, 0, 1, 0, 2, 0};
    int five[501] = {0, 0, 0, 0, 0, 1};

    for (int i = 6; i <= n; i++) {
        if (i % 2 == 0) {
            two[i] = two[i / 2] + 1;
        }
        if (i % 5 == 0) {
            five[i] = five[i / 5] + 1;
        }
    }

    int two_sum = 0;
    for (int i = 1; i <= n; i++) {
        two_sum += two[i];
    }

    int five_sum = 0;
    for (int i = 1; i <= n; i++) {
        five_sum += five[i];
    }

    std::cout << std::min(two_sum, five_sum);
    return 0;
}
