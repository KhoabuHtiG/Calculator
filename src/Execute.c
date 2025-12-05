#include "../include/Execute.h"
#include "../include/Format.h"
#include "../include/Calculator.h"
#include "../include/Core.h"
#include "../include/Settings.h"

#define OPTIONS_BASIC_OPERATORS '1'
#define OPTIONS_RANDOM_NUMBERS '2'

void Execute(const char option) {
    switch (option) {
        case OPTIONS_BASIC_OPERATORS:
            ClearScreen();
            BasicOpers();
            break;
        case OPTIONS_RANDOM_NUMBERS:
            ClearScreen();
            int result = GenerateRandomNumber();

            printf("%d\n", result);

            WaitForEnter();
            break;
        case SETTINGS_OPTION:
            ClearScreen();
            SettingsFunc();
            break;
        default:
            printf("Invalid option. Please try again\n");
    }
}