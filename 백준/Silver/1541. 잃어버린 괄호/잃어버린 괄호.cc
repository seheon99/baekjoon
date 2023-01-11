#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int operands[50];
    char operators[50];
    int tot;
    std::cin >> tot;

    int length = 0;
    while (std::cin >> operators[length] >> operands[length]) {
        length += 1;
    }

    bool plus = true;
    for (int i = 0; i < length; i++) {
        if (plus == true && operators[i] == '+') {
            tot += operands[i];
        } else {
            plus = false;
            tot -= operands[i];
        }
    }
    std::cout << tot;
    return 0;
}
