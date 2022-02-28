#include <iostream>

static const int MAX_NUMBER_OF_LECTURES = 100000;
static const int MAX_LENGTH_OF_LECTURE = 10000;

static int number_of_blueray;
static int number_of_lectures;
static int length_of_lectures[MAX_NUMBER_OF_LECTURES];

static int search_minimum_size_of_blueray(int max_length, int sum_of_lengths)
{
	int left = max_length;
	int right = sum_of_lengths;
	int answer;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int count_blueray = 0;

		for (int current_size = 0, idx = 0; idx < number_of_lectures; idx++)
		{
			current_size += length_of_lectures[idx];
			if (current_size > mid)
			{
				current_size = length_of_lectures[idx];
				count_blueray += 1;
			}
		}

		if (count_blueray < number_of_blueray)
		{
			right = mid - 1;
			answer = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return (answer);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int max_length = 0;
	int sum_of_lengths = 0;

	std::cin >> number_of_lectures >> number_of_blueray;
	for (int idx = 0; idx < number_of_lectures; idx++)
	{
		std::cin >> length_of_lectures[idx];
		max_length = std::max(max_length, length_of_lectures[idx]);
		sum_of_lengths += length_of_lectures[idx];
	}

	std::cout << search_minimum_size_of_blueray(max_length, sum_of_lengths);
	return (0);
}
