#include "../include/Execute.h"
#include "../include/Format.h"
#include "../include/Calculator.h"
#include "../include/Core.h"
#include "../include/Settings.h"

#define OPTIONS_BASIC_OPERATORS '1'
#define OPTIONS_RANDOM_NUMBERS '2'
#define OPTIONS_SETTINGS 's'

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
        case OPTIONS_SETTINGS:
            ClearScreen();
            SettingsFunc();
            break;
    }
}