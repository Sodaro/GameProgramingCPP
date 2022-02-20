#include <iostream>
#include <set>
#include <string>

int main()
{
    int number = 1234;
    std::set<char> digits;
    
    std::string numberStr = std::to_string(number);


    bool isLucky = true;
    for (auto c : numberStr)
    {
        if (digits.find(c) == digits.end())
        {
            digits.insert(c);
        }
        else
        {
            isLucky = false;
            break;
        }
    }

    if (isLucky)
    {
        std::cout << number << " is a lucky number." << std::endl;
    }
    else
    {
        std::cout << number << " is not a lucky number." << std::endl;
    }
}
