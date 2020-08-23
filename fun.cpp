#include "fun.h"

char getChar() {
    std::string input;
    std::getline(std::cin, input);
    while (input.length() != 1)
    {
        std::cout << "You have to enter one character, try again: ";
        std::getline(std::cin, input);
    }
    return input[0];
}

