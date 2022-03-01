#include <iostream>
#include <string>
int main()
{
    int number = 100235;
    std::string numberString = std::to_string(number);
    int length = numberString.length();

    for (int i = 0; i < numberString.length(); i++)
    {
        std::cout << numberString[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Last Digit: " << numberString[length - 1] << std::endl;

    for (int i = length - 1; i >= 0; i--)
    {
        std::cout << numberString[i] << " ";
    }
}