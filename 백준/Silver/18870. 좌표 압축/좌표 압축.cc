#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::pair<int, int>> x;

    int n;
    std::cin >> n;
    x.reserve(n);
    for (int i = 0; i < n; i++) {
        int xi;
        std::cin >> xi;
        x.push_back(std::make_pair(xi, i));
    }
    std::sort(x.begin(), x.end());
    int count = 0;
    for (int i = 0; i < n;) {
        int xi = x[i].first;

        while (x[i].first == xi) {
            x[i].first = count;
            i += 1;
        }
        count++;
    }
    std::sort(x.begin(), x.end(),
              [](std::pair<int, int> l, std::pair<int, int> r) -> bool {
                  return l.second < r.second;
              });
    for (int i = 0; i < n; i++) {
        std::cout << x[i].first << " ";
    }
    std::cout << std::endl;
    return 0;
}
