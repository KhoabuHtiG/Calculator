#include "../include/Calculator.h"
#include "../include/Format.h"

#define CLEAR_OPTION 'c'
#define RETURN_OPTION 'r'
double result = 0, addup;

void GetNumber() {
    printf("Enter your number: ");
    scanf("%lf", &addup);
}

static char GetUserChoice(void) {
    char choice;

    if (scanf(" %c", &choice) != 1) {
        while (getchar() != '\n');
        return '\0';
    }

    return tolower(choice);
}

void RunBasicOps(const char choice) {
    switch (choice) {
        case '+':
            Add(&result, addup);
            break;
        case '-':
            Subtract(&result, addup);
            break;
        case '*':
            Multiply(&result, addup);
            break;
        case '/':
            if (result == 0 || addup == 0) {
                printf("Error: Can't divided by zero. Please try again\n");
                break;
            }

            Divided(&result, addup);
            break;
        default:
            printf("Invalid operator. Please try again\n");
            break;
    }
}

void BasicOps() {
    char choice;
    printf("Current result: %lf\n", result);

    while (1) {
        printf("Operators: '+', '-', '*', '/' || 'r': Return to menu || 'c': Clear result\n");
        printf("Choose: ");
        
        choice = GetUserChoice();

        if (choice == RETURN_OPTION) return;
        if (choice == CLEAR_OPTION) {
            result = 0;
            continue;
        }

        GetNumber();
        RunBasicOps(choice);

        printf("Current result: %lf\n", result);
    }
}