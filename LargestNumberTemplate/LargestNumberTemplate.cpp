#include <iostream>

template <class T>
T isGreater(T a, T b)
{
    return a > b;
}


int main()
{
    int a = 5;
    int b = 3;

    if (isGreater(a, b))
    {
        std::cout << a << " is greater than " << b;
    }
    else
    {
        std::cout << a << " is not greater than " << b;
    }
}
