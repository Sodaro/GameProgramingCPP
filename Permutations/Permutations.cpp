#include <iostream>
#include <string>


void swap(char& c1, char& c2)
{
    char temp = c2;
    c2 = c1;
    c1 = temp;
}

void getPermutations(std::string text, int begin, int end)
{
    if (begin == end)
    {
        std::cout << text << std::endl;
        return;
    }
        
    for (int i = begin; i <= end; i++)
    {
        swap(text[begin], text[i]);
        getPermutations(text, begin + 1, end);
        swap(text[begin], text[i]);
    }
}

int main()
{
    std::string text = "ABC";
    getPermutations(text, 0, text.length() - 1);
    return 0;
}
