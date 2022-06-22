#include <iostream>
#include <string>

int main(void)
{
    int N;
    int count;
    
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        count = 0;
        std::string str;
        bool success = true;
        
        std::cin >> str;
        for (auto iter = str.begin(); iter != str.end(); iter++)
        {
            if (*iter == '(')
            {
                count++;
            }
            else if (*iter == ')' && count > 0)
            {
                count--;
            }
            else
            {
                std::cout << "NO\n";
                success = false;
                break;
            }
        }
        if (!success)
        {
			continue;
        }
        if (count > 0)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
        }
    }
    return 0;
}
