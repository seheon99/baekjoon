#include <iostream>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#include <functional>

#include <climits>

static const int MAX_NUMBER_OF_VERTEXES = 20000;
static const int MAX_NUMBER_OF_EDGES = 300000;
static const int MAX_WEIGHT = 10;

static const int INF = MAX_NUMBER_OF_EDGES * MAX_WEIGHT + 1;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int number_of_vertexes;
	int number_of_edges;
	int start_point;

	std::map<int, int> paths[MAX_NUMBER_OF_VERTEXES + 1];

	std::cin >> number_of_vertexes >> number_of_edges >> start_point;
	for (int i = 0; i < number_of_edges; i++)
	{
		int u, v, weight;

		std::cin >> u >> v >> weight;

		auto path = paths[u].find(v);
		if (path == paths[u].end())
		{
			paths[u].insert(std::make_pair(v, weight));
		}
		else
		{
			path->second = std::min(path->second, weight);
		}
	}

	int minimal_cost[MAX_NUMBER_OF_VERTEXES + 1];

	for (int i = 1; i <= number_of_vertexes; i++)
	{
		minimal_cost[i] = INF;
	}
	minimal_cost[start_point] = 0;

	// (weight, current_point)
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > queue;

	queue.push(std::make_pair(0, start_point));
	while (queue.empty() == false)
	{
		int weight = queue.top().first;
		int current_point = queue.top().second;
		queue.pop();

		if (minimal_cost[current_point] < weight)
		{
			continue ;
		}
		for (auto path : paths[current_point])
		{
			if (weight + path.second <= minimal_cost[path.first])
			{
				queue.push(std::make_pair(weight + path.second, path.first));
				minimal_cost[path.first] = weight + path.second;
			}
		}
	}
	for (int i = 1; i <= number_of_vertexes; i++)
	{
		if (minimal_cost[i] == INF)
		{
			std::cout << "INF" << '\n';
		}
		else
		{
			std::cout << minimal_cost[i] << '\n';
		}
	}
	return (0);
}
