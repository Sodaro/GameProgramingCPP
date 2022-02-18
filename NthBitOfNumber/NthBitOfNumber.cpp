#include <iostream>
#include <bitset>
#include <string>

void printBits(char value)
{
    std::cout << std::bitset<8>(value) << " " << (int)value << std::endl;
}

bool getNthBit(char value, int n)
{
    return (value & 1 << n);
}

void setNthBit(char& value, int n, bool bitValue)
{
    if (bitValue == 1)
    {
        //shift a 1 to the nth bit and or it to set true
        value |= (1 << n);
    }
    else
    {
        //shift a 1 to the nth bit and "and" it with the not to set false
        value &= ~(1 << n);
    }
}

void toggleNthBit(char& value, int n)
{
    value ^= 1 << n;

}

int main()
{
    char value = 12;
    printBits(value);
    setNthBit(value, 2, 0);
    printBits(value);
    setNthBit(value, 3, 0);
    printBits(value);
}

