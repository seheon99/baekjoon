#include <iostream>

using number_type = long long;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n_coords;
    number_type x[10000];
    number_type y[10000];

    std::cin >> n_coords;
    for (int i = 0; i < n_coords; i++) {
        std::cin >> x[i] >> y[i];
    }

    number_type area = 0;
    for (int i = 0; i < n_coords - 1; i++) {
        area += (x[i] + x[i + 1]) * (y[i] - y[i + 1]);
    }
    area += (x[n_coords - 1] + x[0]) * (y[n_coords - 1] - y[0]);
    area = std::abs(area);

    std::cout << area / 2 << '.' << (area % 2 ? 5 : 0) << std::endl;
    return 0;
}