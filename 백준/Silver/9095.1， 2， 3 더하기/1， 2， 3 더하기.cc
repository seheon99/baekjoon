#include <iostream>

static const int MAX = 11;

static int count_expressions_with_123(int integer)
{
	static int cache[MAX] = {0, 1, 2, 4, };
	static bool cached[MAX] = {true, true, true, true};

	if (cached[integer])
	{
		return (cache[integer]);
	}

	int& count = cache[integer];
	cached[integer] = true;

	count = count_expressions_with_123(integer - 1);
	count += count_expressions_with_123(integer - 2);
	count += count_expressions_with_123(integer - 3);
	return (count);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int loop_count;

	std::cin >> loop_count;
	for (int i = 0; i < loop_count; i++)
	{
		int integer;

		std::cin >> integer;
		std::cout << count_expressions_with_123(integer) << "\n";
	}
	return (0);
}
