#include <queue>
#include <vector>
#include <utility>
#include <iostream>

int main(void)
{
	using max_heap_int = std::priority_queue<int>;
	using min_heap_int = std::priority_queue<int, std::vector<int>, std::greater<int> >;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned long number_of_calls;
	max_heap_int small_group;
	min_heap_int big_group;

	std::cin >> number_of_calls;
	for (unsigned long i = 1; i <= number_of_calls; i++)
	{
		int number;

		std::cin >> number;
		if (big_group.size() > 0 && number > big_group.top())
		{
			big_group.push(number);
		}
		else
		{
			small_group.push(number);
		}

		if (small_group.size() > (i + 1) / 2)
		{
			big_group.push(small_group.top());
			small_group.pop();
		}
		else if (big_group.size() > i / 2)
		{
			small_group.push(big_group.top());
			big_group.pop();
		}

		std::cout << small_group.top() << '\n';
	}
	return (0);
}
