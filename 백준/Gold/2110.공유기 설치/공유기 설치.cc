#include <iostream>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int number_of_house;
	int number_of_router;
	int coord_of_house[200000];

	int left = 0, right = 0;

	std::cin >> number_of_house >> number_of_router;
	for (int i = 0; i < number_of_house; i++)
	{
		std::cin >> coord_of_house[i];
		right = std::max(right, coord_of_house[i]);
	}
	std::sort(coord_of_house, coord_of_house + number_of_house);

	int maximum_length;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int count_router = 0;
		int coord_of_last_router = -1;

		for (int i = 0; i < number_of_house; i++)
		{
			if (coord_of_last_router != -1 \
				&& coord_of_last_router + mid > coord_of_house[i])
			{
				continue ;
			}
			else
			{
				coord_of_last_router = coord_of_house[i];
				if (++count_router == number_of_router)
				{
					break ;
				}
			}
		}
		if (count_router < number_of_router)
		{
			right = mid - 1;
		}
		else
		{
			maximum_length = mid;
			left = mid + 1;
		}
	}

	std::cout << maximum_length;
	return (0);
}
