#include <iostream>

static const int MAX_LENGTH_OF_SEQUENCE = 1000;

static int length_of_sequence;
static int sequence[MAX_LENGTH_OF_SEQUENCE];

static int get_max_length_of_asc_seq_iter(int index)
{
	static int cache[MAX_LENGTH_OF_SEQUENCE];
	static bool cached[MAX_LENGTH_OF_SEQUENCE];

	if (cached[index])
	{
		return (cache[index]);
	}

	int& max_length = cache[index];
	cached[index] = true;

	max_length = 1;
	for (int i = index; i < length_of_sequence; i++)
	{
		if (sequence[index] < sequence[i])
		{
			max_length = std::max(max_length, 1 + get_max_length_of_asc_seq_iter(i));
		}
	}
	return (max_length);
}

static int get_max_length_of_asc_seq()
{
	int max = 0;

	for (int i = 0; i < length_of_sequence; i++)
	{
		max = std::max(max, get_max_length_of_asc_seq_iter(i));
	}
	return (max);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> length_of_sequence;
	for (int i = 0; i < length_of_sequence; i++)
	{
		std::cin >> sequence[i];
	}
	std::cout << get_max_length_of_asc_seq();
	return (0);
}
