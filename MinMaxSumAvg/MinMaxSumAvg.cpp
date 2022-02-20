#include <iostream>

int main()
{
    int collection[20] = {
        2,2,2,2,2,
        2,2,2,2,2,
        1,1,1,1,1,
        1,1,1,1,1,
    };

    int min, max, sum;
    float avg;

    min = INT32_MAX;
    max = INT32_MIN;
    sum = 0;
    avg = 0;

    for (int nr : collection)
    {
        if (nr < min)
            min = nr;

        if (nr > max)
            max = nr;

        sum += nr;
    }

    avg = (float)sum / 20;

    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << avg << std::endl;
}
