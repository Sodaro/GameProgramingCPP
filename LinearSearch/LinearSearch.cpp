#include <iostream>

int linearSearch(int value, int* collection, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (collection[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int collection[20] = {
        0,0,0,0,0,
        0,0,3,0,0,
        0,0,0,9,0,
        0,2,0,0,0,
    };

    std::cout << "Collection contains: ";
    for (int nr : collection)
    {
        std::cout << nr << ", ";
    }

    std::cout << std::endl;
    int number;
    std::cout << "Insert number to retrieve index for: ";
    std::cin >> number;

    int index = linearSearch(number, collection, 20);
    if (index == -1)
    {
        std::cout << "Number not found in collection." << std::endl;
    }
    else
    {
        std::cout << "Number found at index: " << index << std::endl;
    }

}
