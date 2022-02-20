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

void setNthBit(int& value, int n)
{

    //OR original value with a value that has a 1 shifted to the nth bit to set
    value |= (1 << n);

}
void clearNthBit(int& value, int n)
{
    //value: 1111;
    //rh value: 0010 -> 1101
    //AND
    //value: 1101
    //shift a 1 to the nth bit, not the shifted int and AND it to clear
    value &= ~(1 << n);
}

void toggleNthBit(int& value, int n)
{
    value ^= 1 << n;

}

int main()
{
    int value = 0;
    printBits(value);
    std::cout << "Setting 2nd bit" << std::endl;
    setNthBit(value, 2);
    printBits(value);
    std::cout << "Clearing 2nd bit" << std::endl;
    clearNthBit(value, 2);
    printBits(value);
    std::cout << "Toggling 2nd bit" << std::endl;
    toggleNthBit(value, 2);
    printBits(value);
}

