#include <iostream>
#include <string>

static std::string add(std::string a, std::string b)
{
    std::string::reverse_iterator a_itr = a.rbegin();
    std::string::reverse_iterator b_itr = b.rbegin();
    std::string result = "";
    bool carry = false;

    while (a_itr != a.rend() && b_itr != b.rend())
    {
        int digit_sum = (*a_itr - '0' + *b_itr - '0' + (carry ? 1 : 0));

        result.insert(result.begin(), digit_sum % 10 + '0');
        carry = digit_sum / 10 > 0;
        a_itr++;
        b_itr++;
    }
    while (a_itr != a.rend())
    {
        int digit_sum = (*a_itr - '0' + (carry ? 1 : 0));

        result.insert(result.begin(), digit_sum % 10 + '0');
        carry = digit_sum / 10 > 0;
        a_itr++;
    }
    while (b_itr != b.rend())
    {
        int digit_sum = (*b_itr - '0' + (carry ? 1 : 0));

        result.insert(result.begin(), digit_sum % 10 + '0');
        carry = digit_sum / 10 > 0;
        b_itr++;
    }
    if (carry)
    {
        result.insert(result.begin(), '1');
    }
    return result;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a;
    std::string b;

    std::cin >> a >> b;
    std::cout << add(a, b);
}
