#include "../include/Execute.h"
#include "../include/Format.h"
#include "../include/Calculator.h"
#include "../include/Core.h"

#define OPTIONS_BASIC_OPERATORS '1'
#define OPTIONS_RANDOM_NUMBERS '2'

void Execute(const char option) {
    switch (option) {
        case OPTIONS_BASIC_OPERATORS:
            ClearScreen();
            BasicOpers();
            break;
        case OPTIONS_RANDOM_NUMBERS:
            printf("%d\n", GenerateRandomNumber());
            break;
        default:
            printf("Invalid options: %c. Please try again.\n", option);
            break;
    }
}