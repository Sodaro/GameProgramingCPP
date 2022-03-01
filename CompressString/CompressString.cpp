#include <iostream>
#include <string>
#include <cassert>

std::string decompress(std::string text)
{
    std::string decompressed = "";
    std::string count = "";
    int length = text.length();
    char charToWrite = text[0];
    int timesToWrite = 0;
    for (int i = 1; i < length; i++)
    {
        if (std::isdigit(text[i]))
        {
            int pos = i;
            std::string countstr = "";
            while (std::isdigit(text[pos]) && pos < length)
            {
                countstr += text[pos];
                pos++;
            }
            timesToWrite = std::stoi(countstr);

            for (int i = 0; i < timesToWrite; i++)
                decompressed += charToWrite;

            i = pos-1;
        }
        else
        {
            charToWrite = text[i];
        }
    }
    return decompressed;
}

std::string compress(std::string text)
{
    std::string compressed = "";
    int charCount = 0;
    int length = text.length();
    for (int i = 0; i < length; i++)
    {
        charCount++;
        int next = i + 1;
        if (next == length || text[next] != text[i])
        {
            compressed += text[i] + std::to_string(charCount);
            charCount = 0;
        }   
    }
    return compressed;
}

int main()
{
    std::string input = "aaaaaaaaaaaaaaabbbbaaaaabbbccDDDxxxEEE";
    std::string compressedInput = compress(input);
    std::string decompressedInput = decompress(compressedInput);
    assert(input == decompressedInput);
}
