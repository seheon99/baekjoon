#include <iostream>

static const int MAX_NUMBER_OF_SONGS = 50;
static const int MAX_VOLUME = 1000;

static int number_of_songs;
static int max_volume;
static int diff_volumes[MAX_NUMBER_OF_SONGS];

static int cache[MAX_NUMBER_OF_SONGS][MAX_VOLUME + 1];
static bool cached[MAX_NUMBER_OF_SONGS][MAX_VOLUME + 1];

static int maximum_final_volume(int index, int prev_volume)
{
	if (prev_volume < 0 || prev_volume > max_volume)
	{
		return (-1);
	}
	if (index >= number_of_songs)
	{
		return (prev_volume);
	}
	if (cached[index][prev_volume])
	{
		return (cache[index][prev_volume]);
	}

	int volume_up = maximum_final_volume(index + 1, prev_volume + diff_volumes[index]);
	int volume_down = maximum_final_volume(index + 1, prev_volume - diff_volumes[index]);

	cache[index][prev_volume] = std::max(volume_up, volume_down);
	cached[index][prev_volume] = true;
	return (cache[index][prev_volume]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int start_volume;

	std::cin >> number_of_songs >> start_volume >> max_volume;
	for (int index = 0; index < number_of_songs; index++)
	{
		std::cin >> diff_volumes[index];
	}

	std::cout << maximum_final_volume(0, start_volume);

	return (0);
}
