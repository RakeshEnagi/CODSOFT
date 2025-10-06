#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int secretNumber = std::rand() % 100 + 1;
    int guess;

    std::cout << "Guess the number (between 1 and 100): ";

    do {
        std::cin >> guess;

        if (guess > secretNumber) {
            std::cout << "Too high. Try again: ";
        } else if (guess < secretNumber) {
            std::cout << "Too low. Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
