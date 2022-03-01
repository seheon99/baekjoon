#include <iostream>

static const int MAX_NUMBER_OF_GLASS = 10000;
static const int MAX_AMOUNT_OF_WINE = 1000;
static const int MAX_COUNT = 3;

static int number_of_glass;
static int amount_of_wine[MAX_NUMBER_OF_GLASS];

static int cache[MAX_NUMBER_OF_GLASS][MAX_COUNT];
static bool cached[MAX_NUMBER_OF_GLASS][MAX_COUNT];

static int drink_max(int index, int count)
{
	if (index >= number_of_glass)
	{
		return (0);
	}
	if (cached[index][count])
	{
		return (cache[index][count]);
	}

	int& amount = cache[index][count];
	cached[index][count] = true;

	amount = drink_max(index + 1, 0);
	if (count + 1 < MAX_COUNT)
	{
		int drink = amount_of_wine[index] + drink_max(index + 1, count + 1);
		amount = std::max(amount, drink);
	}
	return (amount);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> number_of_glass;
	for (int i = 0; i < number_of_glass; i++)
	{
		std::cin >> amount_of_wine[i];
	}

	std::cout << drink_max(0, 0);
	return (0);
}
