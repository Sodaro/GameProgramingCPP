#include <iostream>

template <class T>

void Swap(T& a, T& b)
{
    a += b;
    b = a - b;
    a -= b;
}

int main()
{
    int a = 5, b = 7;
    std::cout << "a:" << a << ", b:" << b << std::endl;
    std::cout << "Swapping..." << std::endl;

    Swap(a, b);

    std::cout << "a:" << a << ", b:" << b << std::endl;
}
