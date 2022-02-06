#include <iostream>

int main(void)
{
	int number_of_trees;
	int required_trees;
	int trees[1000000];

	int left = 0, right = 0, max_height = 0;

	std::cin >> number_of_trees >> required_trees;
	for (int idx = 0; idx < number_of_trees; idx++)
	{
		std::cin >> trees[idx];
		right = std::max(right, trees[idx]);
	}
	while (left < right)
	{
		int mid = ((unsigned int) left + right) / 2;
		unsigned long long chopped_length = 0;
		for (int idx = 0; idx < number_of_trees; idx++)
		{
			chopped_length += std::max(trees[idx] - mid, 0);
		}
		if (chopped_length >= required_trees)
		{
			max_height = mid;
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	std::cout << max_height << std::endl;
}
