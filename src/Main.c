#include "../include/Core.h"
#include "../include/Execute.h"

#define QUIT_OPTION 'r'
#define MENU_OPTION 'm'

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
        printf("Thanks for using!");
        return true;
    }

    if (option == MENU_OPTION) {
        ClearScreen();
        PrintMenu();
        return false;
    }

    return false;
}

int main() {
    char option;
    
    ClearScreen();
    PrintMenu();

    while (1) {
        printf("'r': Quit || 'm': Show menu\n");
        printf("Choose: ");

        option = GetUserChoice();

        if (HandleUserInput(option)) {
            break;
        }

        Execute(option);
    }
}