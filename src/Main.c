#include "../include/Core.h"
#include "../include/Execute.h"

char *menu[] = {"---Menu---", "1. Basic Operators", "2. Generate Random Number"};
int menuLength = sizeof(menu) / sizeof(menu[0]);

int main() {
    char option;
    ClearScreen();

    for (int i = 0; i < menuLength; i++) {
        printf("%s\n", menu[i]);
    }

    while (1) {
        printf("'r': Quit || 'm': Show menu\n");
        printf("Choose: ");
        scanf(" %c", &option);

        if (option == 'r' || option == 'R') {
            printf("Thanks for using!");
            return 0;
        } else if (option == 'm' || option == 'M') {
            ClearScreen();

            for (int i = 0; i < menuLength; i++) {
                printf("%s\n", menu[i]);
            }

            continue;
        }

        Execute(option);
    }
}