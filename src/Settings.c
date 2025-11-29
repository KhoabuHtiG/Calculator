#include "../include/Core.h"

#define RETURN_OPTION 'r'

char *settingsOption[] = {"1. Change decimals places", "2. Change quit confirming"};
int arrSize = sizeof(settingsOption) / sizeof(settingsOption[0]);

static void PrintPrompt() {
    printf("Settings menu\n");

    for (int i = 0; i < arrSize; i++) {
        printf("%s\n", settingsOption[i]);
    }
}

static char GetUserChoice(void) {
    char choice;

    if (scanf(" %c", &choice) != 1) {
        while (getchar() != '\n');
        return '\0';
    }
    
    return tolower(choice);
}

void ChangeDecimalsPlaces() {
    while (true) {
        printf("Current decimals show: %d\n", GetSettings()->decimals_show);
        printf("Change: 'y' || Return: '%c'\n", RETURN_OPTION);

        printf("Choose: ");
        char choice = GetUserChoice();

        if (choice == 'r') {
            SaveSettings();
            ClearScreen();
            return;
        }

        if (choice == 'y') {
            int value;

            printf("Set a new number: ");
            scanf("%d", &value);

            GetSettings()->decimals_show = value;
            ClearScreen();
        }
    }
}

void ChangeConfirmQuit() {
    while (true) {
        printf("Current quit confirming state: %d\n", GetSettings()->confirm_quit);
        printf("Change: 'y' || Return: '%c'\n", RETURN_OPTION);

        printf("Choose: ");
        char choice = GetUserChoice();

        if (choice == 'r') {
            SaveSettings();
            ClearScreen();
            return;
        }

        if (choice == 'y') {
            int value;

            printf("Set true/false (1 - 0): ");
            scanf("%d", &value);

            if (value != 1 && value != 0) {
                printf("Invalid input. Please try again.\n");
                continue;
            }

            GetSettings()->confirm_quit = value;
            ClearScreen();
        }
    }
}

static void HandleSettingsCommand(char choice) {
    switch (choice) {
        case '1':
            ClearScreen();
            ChangeDecimalsPlaces();
            break;
        case '2':
            ClearScreen();
            ChangeConfirmQuit();
            break;
        default:
            printf("Invalid Option. Please try again.\n");
            break;
    }
}

void SettingsFunc() {
    while (true) {
        PrintPrompt();
        printf("Return: 'r'\n");

        printf("Choose: ");
        char choice = GetUserChoice();

        if (choice == RETURN_OPTION) return;

        HandleSettingsCommand(choice);
        SaveSettings();
    }
}