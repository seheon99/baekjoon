#include <iostream>
#include <vector>

static const int MAX_HEIGHT = 500;

static int height;
static std::vector<int> numbers[MAX_HEIGHT];

static int get_largest_sum(int current_height, int current_index)
{
	static int cache[MAX_HEIGHT][MAX_HEIGHT + 1];
	static bool cached[MAX_HEIGHT][MAX_HEIGHT + 1];

	if (current_height == height)
	{
		return (0);
	}
	if (cached[current_height][current_index])
	{
		return (cache[current_height][current_index]);
	}

	int& sum = cache[current_height][current_index];
	cached[current_height][current_index] = true;

	int left = get_largest_sum(current_height + 1, current_index);
	int right = get_largest_sum(current_height + 1, current_index + 1);

	sum = numbers[current_height][current_index] + std::max(left, right);
	return (sum);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> height;
	for (int i = 0; i < height; i++)
	{
		numbers[i].resize(i + 1);
		for (int j = 0; j <= i; j++)
		{
			std::cin >> numbers[i][j];
		}
	}

	std::cout << get_largest_sum(0, 0);
	return (0);
}
