#include <iostream>
#include <set>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int size;
	std::set<int> numbers;

	std::cin >> size;
	for (int i = 0; i < size; i++)
	{
		int number;
		std::cin >> number;
		numbers.insert(number);
	}
	std::cin >> size;
	for (int i = 0; i < size; i++)
	{
		int number;
		std::cin >> number;
		if (numbers.find(number) != numbers.end())
		{
			std::cout << "1\n";
		}
		else
		{
			std::cout << "0\n";
		}
	}
}
