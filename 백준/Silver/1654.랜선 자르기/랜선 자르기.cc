#include <iostream>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	unsigned int number_of_required_lines;
	int number_of_lines;
	int length_of_line[10000];
	int max_length = 0;

	std::cin >> number_of_lines >> number_of_required_lines;
	for (int i = 0; i < number_of_lines; i++)
	{
		std::cin >> length_of_line[i];
		max_length = std::max(max_length, length_of_line[i]);
	}

	unsigned int left = 1, right = max_length;

	while (left <= right)
	{
		int mid = ((unsigned int) left + right) / 2;
		unsigned int count = 0;

		for (int i = 0; i < number_of_lines && count < number_of_required_lines; i++)
		{
			count += length_of_line[i] / mid;
		}
		if (count >= number_of_required_lines)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	std::cout << right;
	return (0);
}
