#include "../include/Core.h"
#include "../include/Execute.h"

int main() {
    char option;
    
    ClearScreen();
    PrintMenu();

    while (1) {
        printf("'r': Quit || 'm': Show menu\n");
        printf("Choose: ");
        scanf(" %c", &option);

        if (option == 'r' || option == 'R') {
            printf("Thanks for using!");
            return 0;
        } else if (option == 'm' || option == 'M') {
            ClearScreen();
            PrintMenu();

            continue;
        }

        Execute(option);
    }
}