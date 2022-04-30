#include <iostream>
#include <string>

static int sum_of_digits(int number)
{
    int sum = 0;

    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string number_string;
    while (std::cin >> number_string)
    {
        if (number_string == "0")
            break;
        int input_number = 0;
        for (auto ch : number_string)
            input_number += ch - '0';
        while ((input_number = sum_of_digits(input_number)) > 9)
            ;
        std::cout << input_number << '\n';
    }
    return 0;
}
