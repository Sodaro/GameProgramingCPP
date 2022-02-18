#include <iostream>

bool isOdd(int number)
{
    return (number & 1) == 1;
}

int main()
{
    int number = 3;
    if (isOdd(number))
    {
        std::cout << number << " is an odd number." << std::endl;
    }
    else
    {
        std::cout << number << " is an even number." << std::endl;
    }
    
}
