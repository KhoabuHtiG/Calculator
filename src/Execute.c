#include "../include/Execute.h"
#include "../include/Format.h"
#include "../include/Calculator.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void execute(const char option) {
    switch (option) {
        case '1':
            clearScreen();
            basicOps();
            break;
        case '2':
            printf("%d\n", generateRandomNumber());
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}