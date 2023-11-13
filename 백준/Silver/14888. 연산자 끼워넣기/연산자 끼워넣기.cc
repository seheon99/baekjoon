#include <iostream>

const int RESULT_MAX = 1000000000;
const int RESULT_MIN = -1000000000;
const int N_MAX = 11;

static int numbers[N_MAX];
static int n;

static int max = RESULT_MIN;
static int min = RESULT_MAX;

static void calc(int add, int sub, int mul, int div, int curr, int index) {
    if (index == n) {
        min = std::min(min, curr);
        max = std::max(max, curr);
        return;
    }

    if (add > 0) {
        calc(add - 1, sub, mul, div, curr + numbers[index], index + 1);
    }
    if (sub > 0) {
        calc(add, sub - 1, mul, div, curr - numbers[index], index + 1);
    }
    if (mul > 0) {
        calc(add, sub, mul - 1, div, curr * numbers[index], index + 1);
    }
    if (div > 0) {
        calc(add, sub, mul, div - 1, curr / numbers[index], index + 1);
    }
}

int main(void) {
    int add, sub, mul, div;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    std::cin >> add >> sub >> mul >> div;
    calc(add, sub, mul, div, numbers[0], 1);
    std::cout << max << std::endl;
    std::cout << min << std::endl;
    return 0;
}