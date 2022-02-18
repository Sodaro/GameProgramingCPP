#include <iostream>
#include <string>
#include <stack>

bool isPalindrome(std::string input, int length)
{
    int midPoint = length / 2;
    std::stack<char> firstHalf;

    //if even length then both halves will be mirrored, if odd length the parts on the sides of the mid point will be mirrored
    bool evenLength = length % 2 == 0;
    for (int i = 0; i < length; i++)
    {
        if (i >= midPoint)
        {
            if (i == midPoint && !evenLength)
            {
                continue;
            }
            char c = firstHalf.top();
            firstHalf.pop();
            if (c != input[i])
            {
                return false;
            }
        }
        else
        {
            firstHalf.push(input[i]);
        }
    }
    return true;
}

bool isPalindromeRecursive(std::string input, int index, int endIndex)
{
    //compare first and last
    if (index == endIndex)
    {
        return true;
    }
    else if (input[index] != input[endIndex])
    {
        return false;
    }

    if (index < endIndex + 1)
    {
        //compare second and second to last and so on
        return isPalindromeRecursive(input, index + 1, endIndex - 1);
    }
    
    return true;
}

int main()
{
    std::string input;
    std::cout << "Input a string to check for palindrome" << std::endl;
    std::cin >> input;
    
    if (isPalindromeRecursive(input, 0, input.length()-1))
    {
        std::cout << "Input is palindrome" << std::endl;
    }
    else
    {
        std::cout << "Input is not a palindrome" << std::endl;
    }
    
}
