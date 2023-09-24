#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const int N_MAX = 300001;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> scores;
    scores.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> scores[i];
    }
    std::sort(scores.begin(), scores.end());

    int n_trimmed = std::round(n * 0.15);
    int sum = 0;
    for (int i = n_trimmed; i < n - n_trimmed; i++) {
        sum += scores[i];
    }
    std::cout << std::round((double)sum / (n - 2 * n_trimmed));
    return 0;
}
