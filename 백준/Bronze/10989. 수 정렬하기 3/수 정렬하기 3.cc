#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int nums[10001] = {
        0,
    };
    int input;
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        ++nums[input];
    }
    for (int i = 0; i < 10001; ++i) {
        if (nums[i] > 0) {
            for (int j = 0; j < nums[i]; ++j) {
                std::cout << i << '\n';
            }
        }
    }
    return 0;
}
