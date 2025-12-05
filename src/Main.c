#include "../include/Core.h"
#include "../include/Execute.h"

#define QUIT_OPTION 'r'

static char GetUserChoice(void) {
    char choice;

    if (scanf(" %c", &choice) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        return '\0';
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    return tolower(choice);
}

static bool HandleUserInput(const char option) {
    if (option != QUIT_OPTION) return false;

    if (GetSettings()->confirm_quit == 1) {
        printf("Are you sure you want to quit? Your results will not be saved (y/n): ");
        char quitChoice = GetUserChoice();

        if (quitChoice == 'y') {
            printf("Thanks for using!\n");
            return true;
        }

        return false;
    }

    printf("Thanks for using!\n");
    return true;
}

static void PrintPrompt() {
    printf("'%c': Quit || '%c': Settings\n", QUIT_OPTION, SETTINGS_OPTION);
    printf("Choose: ");
}

int main() {
    char menuOption;
    
    if (!GetData()) {
        printf("Failed to get data\n");
        return 1;
    }

    while (true) {
        ClearScreen();
        PrintMenu();

        PrintPrompt();
        menuOption = GetUserChoice();

        if (HandleUserInput(menuOption)) break;

        Execute(menuOption);
    }
}