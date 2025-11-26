#include "../include/Core.h"

#define RETURN_OPTION 'r'

char *settingsOption[] = {"1. Change decimals_places"};
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
        printf("Current quit comfirming state: %d\n", GetSettings()->comfirm_quit);
        printf("Change: 'y' || Return: '%c'\n", RETURN_OPTION);

        printf("Choose: ");
        char choice = GetUserChoice();

        if (choice == 'r') {
            ClearScreen();
            return;
        }

        if (choice == 'y') {
            int new;

            printf("Set a new number (0 - 14): ");
            scanf("%d", &new);

            GetSettings()->decimals_show = new;
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