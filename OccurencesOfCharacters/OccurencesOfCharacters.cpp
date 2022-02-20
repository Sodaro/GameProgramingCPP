#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::cout << "Enter a text (only letters A-Z, a-z) to count letter occurrence in: " << std::endl;
    
    std::getline(std::cin, input);

    int upperCaseStart = 'A';
    int upperCaseEnd = 'Z';
    int lowerCaseStart = 'a';
    int lowerCaseEnd = 'z';

    int letterCount[26] = {0};

    for (auto c : input)
    {
        int index = 0;
        if (c - lowerCaseStart < 0)
        {
            index = c - upperCaseStart;
        }
        else
        {
            index = c - lowerCaseStart;
        }
        letterCount[index]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letterCount[i] == 0)
            continue;

        std::cout << (char)(upperCaseStart + i) << ": " << letterCount[i] << std::endl;
    }

}
