#include <iostream>

int main(void)
{
	int size;
	char map[100][100];
	int horizontalSeats = 0, verticalSeats = 0;

	std::cin >> size;
	for (int i = 0; i < size; i++)
		std::cin >> map[i];

	for (int i = 0; i < size; i++)
	{
		int hCount = 0, vCount = 0;
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] == '.')
				hCount++;
			else
			{
				if (hCount >= 2)
					horizontalSeats++;
				hCount = 0;
			}

			if (map[j][i] == '.')
				vCount++;
			else
			{
				if (vCount >= 2)
					verticalSeats++;
				vCount = 0;
			}
		}
		if (hCount >= 2)
			horizontalSeats++;
		if (vCount >= 2)
			verticalSeats++;
	}
	std::cout << horizontalSeats << " " << verticalSeats << std::endl;
	return (0);
}
