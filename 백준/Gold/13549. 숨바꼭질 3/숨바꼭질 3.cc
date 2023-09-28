#include <iostream>
#include <queue>

const int X_MAX = 100001;

int main(void) {
    int x, target_x, valid_x;

    std::cin >> x >> target_x;
    valid_x = std::min(target_x + (target_x - x), X_MAX);
    if (target_x < x) {
        std::cout << x - target_x;
        return 0;
    }

    using T = std::pair<int, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> queue;
    bool visited[X_MAX] = {false};

    visited[x] = true;
    queue.push({0, x});
    while (queue.empty() == false) {
        auto [t, x] = queue.top();
        queue.pop();

        if (x == target_x) {
            std::cout << t;
            break;
        }

        if (x * 2 < valid_x && visited[x * 2] == false) {
            visited[x * 2] = true;
            queue.push({t, x * 2});
        }
        if (x - 1 >= 0 && visited[x - 1] == false) {
            visited[x - 1] = true;
            queue.push({t + 1, x - 1});
        }
        if (x + 1 < valid_x && visited[x + 1] == false) {
            visited[x + 1] = true;
            queue.push({t + 1, x + 1});
        }
    }
    return 0;
}
