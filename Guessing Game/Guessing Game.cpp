#include <iostream>
#include <time.h>
#include <string>
int main()
{
    srand(time(NULL));

    int number, guess, nrOfGuesses;

    number = rand() % 100 + 1;
    guess = -1;
    nrOfGuesses = 0;

    std::string highReply = "Your guess is higher";
    std::string lowReply = "Your guess is lower";

    std::cout << "What number between 0-100 (inclusive) am I thinking off?";

    
    do
    {
        std::cin >> guess;

        nrOfGuesses++;

        if (guess < number)
            std::cout << lowReply << std::endl;
        else if (guess > number)
            std::cout << highReply << std::endl;

    } while (guess != number);
    std::cout << "Correct, it took you " << nrOfGuesses << " guesses." << std::endl;
}
