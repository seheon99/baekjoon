#include <iostream>

int count_snacks(int *length_of_snacks, int number_of_snacks, int length)
{
	int sum = 0;

	for (int i = 0; i < number_of_snacks; i++)
		sum += length_of_snacks[i] / length;
	return (sum);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int number_of_cousins;
	int number_of_snacks;
	int length_of_snacks[1000000];

	std::cin >> number_of_cousins >> number_of_snacks;
	for (int i = 0; i < number_of_snacks; i++)
		std::cin >> length_of_snacks[i];

	int max_length = 0;

	for (int left = 1, right = 1000000000; left <= right; )
	{
		int mid = (left + right) / 2;
		if (count_snacks(length_of_snacks, number_of_snacks, mid) >= number_of_cousins)
		{
			max_length = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	std::cout << max_length;
}
