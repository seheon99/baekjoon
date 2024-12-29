#include <iostream>
#include <algorithm>

static const int HOUSE_MAX = 1000;

static const int N_COLORS = 3;
enum Color {
    RED,
    GREEN,
    BLUE
};

static int n_houses;
static int costs[HOUSE_MAX][N_COLORS];

static int cache[HOUSE_MAX][N_COLORS][N_COLORS];
static bool cached[HOUSE_MAX][N_COLORS][N_COLORS];

static int paint_house(int index, int prev_color, int first_color) {
	if (index >= n_houses) {
		return 0;
	}
	if (cached[index][prev_color][first_color]) {
		return (cache[index][prev_color][first_color]);
	}

	int cost_min = INT32_MAX;
	for (int color = 0; color < N_COLORS; color++) {
		if (color == prev_color) {
			continue ;
		}
		if (index == n_houses - 1 && color == first_color) {
			continue ;
		}
		cost_min = std::min(
            cost_min,
            costs[index][color] + paint_house(index + 1, color, first_color)
        );
	}

	cache[index][prev_color][first_color] = cost_min;
	cached[index][prev_color][first_color] = true;
	return (cost_min);
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n_houses;
	for (int i = 0; i < n_houses; i++) {
		for (int color = 0; color < N_COLORS; color++) {
			std::cin >> costs[i][color];
		}
	}

	int red_start = costs[0][RED] + paint_house(1, RED, RED);
	int green_start = costs[0][GREEN] + paint_house(1, GREEN, GREEN);
	int blue_start = costs[0][BLUE] + paint_house(1, BLUE, BLUE);

	std::cout << std::min({red_start, green_start, blue_start});

	return (0);
}