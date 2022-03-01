#include <iostream>

static const int MAX_NUMBER_OF_CARDS = 1000;
static const int MAX_PRICE = 10000;

static int number_of_cards;
static int prices[MAX_NUMBER_OF_CARDS + 1];

static int buy(int quantity)
{
	static int buy_cache[MAX_NUMBER_OF_CARDS];
	static bool buy_cached[MAX_NUMBER_OF_CARDS];

	if (quantity <= 0)
	{
		return (0);
	}
	if (buy_cached[quantity])
	{
		return (buy_cache[quantity]);
	}

	int& cost = buy_cache[quantity];
	buy_cached[quantity] = true;

	cost = prices[quantity];
	for (int sub = quantity - 1; sub >= quantity / 2; sub--)
	{
		cost = std::max(cost, buy(sub) + buy(quantity - sub));
	}
	return (cost);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> number_of_cards;
	for (int i = 1; i <= number_of_cards; i++)
	{
		std::cin >> prices[i];
	}
	std::cout << buy(number_of_cards);
	return (0);
}
