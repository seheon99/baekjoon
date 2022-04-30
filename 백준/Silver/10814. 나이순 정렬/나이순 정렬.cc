#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

bool compare_member(const std::tuple<int, std::string, int> &a, const std::tuple<int, std::string, int> &b)
{
    if (std::get<0>(a) == std::get<0>(b))
    {
        return std::get<2>(a) < std::get<2>(b);
    }
    return std::get<0>(a) < std::get<0>(b);
}

int main(void)
{
    int number_of_members;
    std::cin >> number_of_members;

    std::vector<std::tuple<int, std::string, int>> member_table;
    for (int i = 0; i < number_of_members; i++)
    {
        int age;
        std::string name;

        std::cin >> age >> name;
        member_table.push_back(std::make_tuple(age, name, i));
    }
    std::sort(member_table.begin(), member_table.end(), compare_member);
    for (auto member : member_table)
    {
        std::cout << std::get<0>(member) << " " << std::get<1>(member) << '\n';
    }
    return 0;
}
