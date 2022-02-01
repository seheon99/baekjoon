#include <iostream>

static int digitSum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return (sum);
}

int main(void)
{
	int m;

	std::cin >> m;
	for (int n = 0; n <= m; n++)
	{
		if (n + digitSum(n) == m)
		{
			std::cout << n << std::endl;
			return (0);
		}
	}
	std::cout << 0 << std::endl;
	return (0);
}
