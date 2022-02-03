#include <iostream>

int main(void)
{
	int day, number;

	std::cin >> day >> number;

	int first_coeff = 1;
	int second_coeff = 1;
	for (int i = 3; i < day; i++)
	{
		int first_temp = first_coeff;
		int second_temp = second_coeff;
		first_coeff = second_temp;
		second_coeff = first_temp + second_temp;
	}
	for (int i = 1; i < number; i++)
	{
		if ((number - i * first_coeff) % second_coeff == 0)
		{
			std::cout << i << std::endl;
			std::cout << (number - i * first_coeff) / second_coeff << std::endl;
			return 0;
		}
	}
	throw ;
}
