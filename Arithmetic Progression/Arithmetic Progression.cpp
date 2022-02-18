#include <iostream>
#include <vector>
#include <string>

const int ARR_SIZE = 4;

bool hasArithmeticProgression(std::vector<int> numbers)
{
    int difference, lastDifference;
    for (int i = 1; i < numbers.size(); i++)
    {
        difference = numbers[i] - numbers[i - 1];
        if (i > 1)
        {
            if (lastDifference != difference)
                return false;
        }
        lastDifference = difference;
    }
    return true;
}

int main()
{
    std::vector<int> numberSequence;

    std::cout << "Enter a sequence of numbers (separated by space)" << std::endl;

    std::string numberString;
    std::getline(std::cin, numberString);
    std::string number = "";
    for (int i = 0; i < numberString.length(); i++)
    {
        char c = numberString[i];
        if (c == ' ')
        {
            numberSequence.push_back(std::stoi(number));
            number = "";
        }
        else
            number += c;
    }
    numberSequence.push_back(std::stoi(number));

    if (hasArithmeticProgression(numberSequence))
    {
        std::cout << "The sequence has arithmetic progression" << std::endl;
    }
    else
    {
        std::cout << "The sequence does not have arithmetic progression" << std::endl;
    }
    


}