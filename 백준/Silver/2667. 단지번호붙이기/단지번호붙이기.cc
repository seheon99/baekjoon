#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using pair = std::pair<int, int>;

constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int map[n][n];
    for (int yi = 0; yi < n; yi++) {
        for (int xi = 0; xi < n; xi++) {
            char ch;
            std::cin >> ch;
            map[yi][xi] = ch == '0' ? -1 : 0;
        }
    }

    std::vector<int> count;
    for (int yi = 0; yi < n; yi++) {
        for (int xi = 0; xi < n; xi++) {
            if (map[yi][xi] == 0) {
                std::queue<pair> work;
                work.push(std::make_pair(xi, yi));
                map[yi][xi] = 1;

                int size = 1;
                while (work.empty() == false) {
                    pair coord = work.front();
                    work.pop();

                    int x = std::get<0>(coord);
                    int y = std::get<1>(coord);

                    for (int i = 0; i < 4; i++) {
                        int xi = x + dx[i];
                        int yi = y + dy[i];

                        if (xi >= 0 && xi < n && yi >= 0 && yi < n &&
                            map[yi][xi] == 0) {
                            work.push(std::make_pair(xi, yi));
                            map[yi][xi] = 1;
                            size += 1;
                        }
                    }
                }

                count.push_back(size);
            }
        }
    }

    std::sort(count.begin(), count.end());
    std::cout << count.size() << '\n';
    for (int i = 0; i < count.size(); i++) {
        std::cout << count[i] << '\n';
    }
    return 0;
}
