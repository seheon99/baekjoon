#include <iostream>

static const int MAX_NUMBER = 1000000;

static int count_minimum_operator(int x)
{
	static int cache[MAX_NUMBER];
	static bool cached[MAX_NUMBER];

	if (x == 1)
	{
		return (0);
	}
	if (cached[x])
	{
		return (cache[x]);
	}

	int& count = cache[x];
	cached[x] = true;

	count = 1 + count_minimum_operator(x - 1);
	if (x % 2 == 0)
	{
		count = std::min(count, 1 + count_minimum_operator(x / 2));
	}
	if (x % 3 == 0)
	{
		count = std::min(count, 1 + count_minimum_operator(x / 3));
	}
	return (count);
}

int main(void)
{
	int number;

	std::cin >> number;
	std::cout << count_minimum_operator(number);
	return (0);
}
