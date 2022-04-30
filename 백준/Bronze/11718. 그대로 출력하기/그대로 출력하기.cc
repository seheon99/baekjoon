#include <iostream>
#include <string>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << '\n';
    }
    return 0;
}
