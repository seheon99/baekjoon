#include <iostream>
#include <iterator>
#include <set>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::multiset<int> data;
        int k;

        std::cin >> k;
        for (int j = 0; j < k; j++) {
            char c;
            int x;

            std::cin >> c >> x;
            if (c == 'I') {
                data.insert(x);
            } else if (c == 'D') {
                if (data.empty()) {
                    continue;
                } else if (x == 1) {
                    data.erase(--data.cend());
                } else if (x == -1) {
                    data.erase(data.cbegin());
                }
            }
        }

        if (data.empty()) {
            std::cout << "EMPTY" << '\n';
        } else {
            std::cout << *data.rbegin() << " " << *data.begin() << '\n';
        }
    }
    return 0;
}
