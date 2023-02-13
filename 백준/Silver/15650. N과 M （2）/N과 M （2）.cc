#include <iostream>

static int n;
static int m;

static void print_comb(int i) {
    static int buffer[10];
    static int top;
    static bool printed[10];

    if (top == m) {
        for (int i = 0; i < m; i++) {
            std::cout << buffer[i] << ' ';
        }
        std::cout << '\n';
    } else {
        while (i <= n) {
            if (printed[i]) {
                continue;
            }

            buffer[top++] = i;
            printed[i] = true;
            print_comb(i + 1);
            printed[i] = false;
            --top;
            ++i;
        }
    }
}

int main(void) {
    std::cin >> n >> m;
    print_comb(1);
    return 0;
}
