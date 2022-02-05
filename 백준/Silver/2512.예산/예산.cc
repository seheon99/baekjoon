#include <iostream>
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))

static int count_of_states;
static int amount_of_money[10000];

static int sum_of_money(int upper_boundary)
{
	int sum = 0;
	for (int i = 0; i < count_of_states; i++)
		sum += MIN(amount_of_money[i], upper_boundary);
	return (sum);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int max_money = 0;
	int total_money;

	std::cin >> count_of_states;
	for (int i = 0; i < count_of_states; i++)
	{
		std::cin >> amount_of_money[i];
		max_money = MAX(amount_of_money[i], max_money);
	}
	std::cin >> total_money;

	int left = total_money / count_of_states;
	int right = max_money;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (sum_of_money(mid) > total_money)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	std::cout << left - 1;
}
