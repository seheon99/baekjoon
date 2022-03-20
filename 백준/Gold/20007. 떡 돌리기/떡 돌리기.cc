#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>

static const int MAX_NUMBER_OF_HOUSES = 1000;
static const int MAX_LENGTH_OF_PATH = 5000000;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int number_of_houses;
	int number_of_roads;
	int walk_per_day;
	int start_point;

	std::cin >> number_of_houses >> number_of_roads >> walk_per_day >> start_point;

	// (destination, path length)
	std::map<int, int> roads[MAX_NUMBER_OF_HOUSES];

	for (int i = 0; i < number_of_roads; i++)
	{
		int house1, house2, road;
		std::cin >> house1 >> house2 >> road;
		roads[house1].insert(std::make_pair(house2, road));
		roads[house2].insert(std::make_pair(house1, road));
	}

	int minimum_length[MAX_NUMBER_OF_HOUSES];
	using min_heap = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > >;
	// (path length, current house)
	min_heap heap;

	for (int i = 0; i < number_of_houses; i++)
	{
		minimum_length[i] = MAX_LENGTH_OF_PATH + 1;
	}
	minimum_length[start_point] = 0;
	heap.push(std::make_pair(0, start_point));
	while (heap.empty() == false)
	{
		int path_length = heap.top().first;
		int current_house = heap.top().second;
		heap.pop();

		if (path_length > minimum_length[current_house])
		{
			continue ;
		}
		for (auto road : roads[current_house])
		{
			int length = path_length + road.second;

			if (length <= minimum_length[road.first])
			{
				minimum_length[road.first] = length;
				heap.push(std::make_pair(length, road.first));
			}
		}
	}

	std::sort(minimum_length, minimum_length + number_of_houses);

	if (minimum_length[number_of_houses - 1] > MAX_LENGTH_OF_PATH || \
		minimum_length[number_of_houses - 1] * 2 > walk_per_day)
	{
		std::cout << "-1";
		return (0);
	}

	int days = 1;
	int walks = 0;

	for (int i = 0; i < number_of_houses; i++)
	{
		if (walks + minimum_length[i] * 2 > walk_per_day)
		{
			walks = 0;
			days += 1;
		}
		walks += minimum_length[i] * 2;
	}
	std::cout << days;
	return (0);
}
