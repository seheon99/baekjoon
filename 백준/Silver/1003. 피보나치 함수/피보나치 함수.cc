#include <iostream>
// #include <utility>
std::pair<int, int> operator+(const std::pair<int, int>& left, const std::pair<int, int>& right)
{
	return {left.first + right.first, left.second + right.second};
}

static const int MAX_NUMBER = 40;

static std::pair<int, int> count_0_1_in_fibonacci(int n)
{
	static std::pair<int, int> cache[MAX_NUMBER + 1] = {{1, 0}, {0, 1}, };
	static bool cached[MAX_NUMBER + 1] = {true, true, };

	if (cached[n])
	{
		return (cache[n]);
	}

	std::pair<int, int>& count = cache[n];
	cached[n] = true;

	count = count_0_1_in_fibonacci(n - 1) + count_0_1_in_fibonacci(n - 2);
	return (count);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int number;
	std::pair<int, int> count;

	std::cin >> number;
	for (int i = 0; i < number; i++)
	{
		int n;

		std::cin >> n;
		count = count_0_1_in_fibonacci(n);
		std::cout << count.first << " " << count.second << "\n";
	}
	return (0);
}
