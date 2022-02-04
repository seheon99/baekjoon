#include <iostream>

int main(void)
{
    std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int board_size, query_size;
	bool row_check[1000001] = {false, }; unsigned long long row_sum = 0; int row_count = 0;
	bool col_check[1000001] = {false, }; unsigned long long col_sum = 0; int col_count = 0;

	std::cin >> board_size >> query_size;
	for (int i = 0; i < query_size; i++)
	{
		char direction;
		int index;

		std::cin >> direction >> index;
		if ((direction == 'R' ? row_check[index] : col_check[index]) == true)
		{
			std::cout << "0" << '\n';
			continue ;
		}
		(direction == 'R' ? row_check[index] = true : col_check[index] = true);
		(direction == 'R' ? row_count++ : col_count++);
		(direction == 'R' ? row_sum += index : col_sum += index);

		unsigned long long sum = \
			  (unsigned long long) board_size * (board_size + 1) / 2 \
			+ (unsigned long long) board_size * index \
			- (unsigned long long) (direction == 'R' ? col_sum : row_sum) \
			- (unsigned long long) (direction == 'R' ? col_count : row_count) * index;

		std::cout << sum << '\n';
	}
	return (0);
}
