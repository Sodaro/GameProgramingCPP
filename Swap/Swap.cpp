#include <iostream>
#include <string>
void swapByReference(int& number1, int& number2)
{
    int val = number1;
    number1 = number2;
    number2 = val;
}

void swapByPointer(int* number1, int* number2)
{
    int val = *number1;
    *number1 = *number2;
    *number2 = val;
}

void mathSwap(int& number1, int& number2)
{
    number1 += number2;
    number2 = number1 - number2;
    number1 -= number2;
}

int main()
{
    int nr1, nr2;
    nr1 = 3; nr2 = 7;
    std::cout << "Original:" << nr1 << nr2 << std::endl;
    std::swap(nr1, nr2);

    std::cout << "After swapping using stl: " << nr1 << " " << nr2 << std::endl;
    swapByReference(nr1, nr2);

    std::cout << "After swapping by reference: " << nr1 << " " << nr2 << std::endl;
    swapByPointer(&nr1, &nr2);

    std::cout << "After swapping by pointer: " << nr1 << " " << nr2 << std::endl;
    mathSwap(nr1, nr2);
    std::cout << "After swapping with math: " << nr1 << " " << nr2 << std::endl;
}
