#include "../include/Core.h"
#include "../include/Execute.h"

#define QUIT_OPTION 'r'
#define SETTINGS_OPTION 's'

static char GetUserChoice(void) {
    char choice;

    if (scanf(" %c", &choice) != 1) {
        while (getchar() != '\n');
        return '\0';
    }
    
    return tolower(choice);
}

static bool HandleUserInput(const char option) {
    if (option == QUIT_OPTION) {
        if (GetSettings()->comfirm_quit = 1) {
            printf("Do you sure want to quit? Any result will not be save. (y/n): ");
            char quitChoice = GetUserChoice();

            if (quitChoice == 'y') {
                printf("Thanks for using!");
                return true;
            }

            return false;
        }

        printf("Thanks for using!");
        return true;
    }

    return false;
}

static void PrintPrompt() {
    printf("'%c': Quit || '%c': Settings\n", QUIT_OPTION, SETTINGS_OPTION);
    printf("Choose: ");
}

int main() {
    char option;
    
    if (!GetData()) {
        printf("Failed to proceed\n");
        return 1;
    }

    while (true) {
        ClearScreen();
        PrintMenu();

        PrintPrompt();
        option = GetUserChoice();

        if (HandleUserInput(option)) {
            break;
        }

        Execute(option);
    }
}