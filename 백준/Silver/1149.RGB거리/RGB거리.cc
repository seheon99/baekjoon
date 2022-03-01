#include <iostream>
#include <algorithm>

static const int MAX_NUMBER_OF_HOUSE = 1000;
static const int MAX_COST_TO_PAINTING = 1000;

static const int NUMBER_OF_COLOR = 3;
static const int RED = 0;
static const int GREEN = 1;
static const int BLUE = 2;

static int number_of_houses;
static int costs[MAX_NUMBER_OF_HOUSE][NUMBER_OF_COLOR];

static int cache[MAX_NUMBER_OF_HOUSE][NUMBER_OF_COLOR];
static bool cached[MAX_NUMBER_OF_HOUSE][NUMBER_OF_COLOR];

static int paint_house(int index, int prev_color)
{
	if (index >= number_of_houses)
	{
		return 0;
	}
	if (cached[index][prev_color])
	{
		return (cache[index][prev_color]);
	}

	int minimum_cost = -1;

	for (int color = RED; color < NUMBER_OF_COLOR; color++)
	{
		if (color == prev_color)
		{
			continue ;
		}

		int cost = costs[index][color] + paint_house(index + 1, color);

		minimum_cost = (minimum_cost == -1 ? cost : std::min(minimum_cost, cost));
	}

	cache[index][prev_color] = minimum_cost;
	cached[index][prev_color] = true;
	return (minimum_cost);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> number_of_houses;
	for (int index = 0; index < number_of_houses; index++)
	{
		for (int color = 0; color < NUMBER_OF_COLOR; color++)
		{
			std::cin >> costs[index][color];
		}
	}

	int red_start = costs[0][RED] + paint_house(1, RED);
	int green_start = costs[0][GREEN] + paint_house(1, GREEN);
	int blue_start = costs[0][BLUE] + paint_house(1, BLUE);

	std::cout << std::min({red_start, green_start, blue_start});

	return (0);
}
