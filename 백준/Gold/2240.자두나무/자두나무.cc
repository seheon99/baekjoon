#include <iostream>

static int cherry_timetable[1000];
static int cache[1000][31][2];
static bool cached[1000][31][2];
static int max_second;
static int max_move_count;

int max_cherry_iter(int current_second, int move_count, int current_position)
{
	if (current_second == max_second)
	{
		return (0);
	}
	if (cached[current_second][move_count][current_position])
	{
		return (cache[current_second][move_count][current_position]);
	}

	int& cache_ref = cache[current_second][move_count][current_position];
	cached[current_second][move_count][current_position] = true;

	cache_ref = max_cherry_iter(current_second + 1, move_count, current_position) \
							+ (cherry_timetable[current_second] == current_position);

	if (move_count < max_move_count)
	{
		int moved_position = (current_position == 1 ? 2 : 1);
		int cherry_moved = max_cherry_iter(current_second + 1, move_count + 1, moved_position) \
												+ (cherry_timetable[current_second] == moved_position);

		cache_ref = std::max(cache_ref, cherry_moved);
	}

	return (cache_ref);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> max_second >> max_move_count;
	for (int i = 0; i < max_second; i++)
	{
		std::cin >> cherry_timetable[i];
	}
	std::cout << max_cherry_iter(0, 0, 1);
	return (0);
}
