#include <iostream>
#include <string>
int main()
{

    std::string text = "Hello World";

    for (int i = text.length() - 1; i >= 0; i--)
    {
        std::cout << text[i];
    }
}
