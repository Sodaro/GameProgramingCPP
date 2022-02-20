#include <iostream>
#include <string>

int main()
{
    int number = 341;
    int digit = 3;

    std::string numberstr = std::to_string(number);
    std::string digitStr = std::to_string(digit);

    if (digitStr.length() > 1)
    {
        std::cout << "The digit input must be a single digit" << std::endl;
        return 1;
    }
        
    char digitChar = '0' + digit;

    bool found = false;
    for (auto c : numberstr)
    {
        if (c == digitChar)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        std::cout << number << " contains the digit: " << digitChar;
    }
    else
    {
        std::cout << number << " does not contain the digit: " << digitChar;
    }

    return 0;
}
