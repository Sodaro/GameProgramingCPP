#include <iostream>
int absoluteValue(int number)
{
    if (number < 0)
        number *= -1;

    return number;
}

int main()
{
    int firstNr, secondNr, result;
    firstNr = -6;
    secondNr = 4;
    result = absoluteValue(firstNr - secondNr);

    std::cout << result << std::endl;
}
