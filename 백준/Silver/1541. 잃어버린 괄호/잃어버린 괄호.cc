#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int number;
    char opchar;
    int tot;
    std::cin >> tot;

    bool plus = true;
    while (std::cin >> opchar >> number) {
        if (plus && opchar == '-') {
            plus = false;
        }
        tot += plus ? number : -number;
    }
    std::cout << tot;
    return 0;
}
