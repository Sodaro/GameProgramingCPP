#include <iostream>
#include <string>

bool checkContains(std::string find_text, std::string search_text)
{
    for (int i = 0; i < search_text.length(); i++)
    {
        int pos = i;
        bool foundWord = true;
        for (int j = 0; j < find_text.length(); j++, pos++)
        {
            if (search_text[pos] != find_text[j])
            {
                foundWord = false;
                break;
            }
        }
        if (foundWord)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string sequence = "Hello World!";
    std::string text = "World!";

    std::cout << "Sentence: \"" << text << "\"" << std::endl;
    std::cout << "Looking for: \"" << sequence << "\"" << std::endl;

    if (checkContains(sequence, text))
    {
        std::cout << "\"" << text << "\" contains: \"" << sequence << "\"";
    }
    else
    {
        std::cout << "\"" << text << "\" does not contain: \"" << sequence << "\"";
    }
}
