#include <iostream>
#include <map>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::multimap<std::string, int> closet;
        for (int i = 0; i < n; i++) {
            std::string name, type;
            std::cin >> name >> type;

            auto iter = closet.find(type);
            if (iter == closet.end()) {
                closet.insert(std::make_pair(type, 1));
            } else {
                iter->second += 1;
            }
        }

        int tot = 1;
        for (auto iter : closet) {
            tot *= iter.second + 1;
        }
        std::cout << tot - 1 << '\n';
    }
    return 0;
}
