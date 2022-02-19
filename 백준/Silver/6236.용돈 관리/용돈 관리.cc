#include <iostream>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int number_of_days, number_of_withdraw;
	int costs[100000];

	int left = 0, right = 10000 * 100000;

	std::cin >> number_of_days >> number_of_withdraw;
	for (int i = 0; i < number_of_days; i++)
	{
		std::cin >> costs[i];
		left = std::max(left, costs[i]);
	}

	int minimal_amount_of_withdraw = left;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int money = 0;
		int left_withdraw = number_of_withdraw;

		for (int i = 0; i < number_of_days; i++)
		{
			if (money < costs[i])
			{
				money = mid - costs[i];
				if (--left_withdraw < 0)
				{
					break ;
				}
			}
			else
			{
				money = money - costs[i];
			}
		}
		if (left_withdraw < 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			minimal_amount_of_withdraw = mid;
		}
	}
	std::cout << minimal_amount_of_withdraw;

	return (0);
}
