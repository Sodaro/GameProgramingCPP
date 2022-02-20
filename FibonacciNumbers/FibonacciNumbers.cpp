#include <iostream>


void recursiveFibonacci(int nr1, int nr2, int max)
{
    int fib = nr1 + nr2;
    std::cout << fib;
    if (fib != max)
    {
        std::cout << ", ";
        nr1 = nr2;
        nr2 = fib;
        return recursiveFibonacci(nr1, nr2, max);
    }
    else
    {
        return;
    }
}



void printFibonacciIteratively(int nr1, int nr2, int max)
{
    for (int fib = 1; fib <= max; fib = nr1 + nr2)
    {
        std::cout << fib;
        nr1 = nr2;
        nr2 = fib;

        if (fib != max)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int input = 34;
    int prevNr1 = 0;
    int prevNr2 = 1;
    std::cout << "0, 1, ";
    printFibonacciIteratively(prevNr1, prevNr2, input);

    std::cout << "0, 1, ";
    recursiveFibonacci(prevNr1, prevNr2, input);
}
