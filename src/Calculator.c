#include "../include/Calculator.h"
#include "../include/Format.h"

#define CLEAR_OPTION 'c'
#define RETURN_OPTION 'r'

static bool GetNumber(double *addup) {
    printf("Enter your number: ");

    if (scanf("%lf", addup) != 1) {
        while (getchar() != '\n');
        printf("Invalid number. Please try again.\n");
        return false;
    }

    return true;
}

static char GetUserChoice(void) {
    char choice;

    if (scanf(" %c", &choice) != 1) {
        while (getchar() != '\n');
        return '\0';
    }

    return tolower(choice);
}

static void RunBasicOps(CalcState *calc, const char choice, double addup) {
    switch (choice) {
        case '+':
            Add(&calc->result, addup);
            break;
        case '-':
            Subtract(&calc->result, addup);
            break;
        case '*':
            Multiply(&calc->result, addup);
            break;
        case '/':
            if (addup == 0) {
                printf("Error: Cannot divide by zero. Please try again\n");
                break;
            }

            Divided(&calc->result, addup);
            break;
        default:
            printf("Invalid operator. Please try again\n");
            break;
    }
}

static void PrintPrompt() {
    printf("Operators: '+', '-', '*', '/' || '%c': Return to menu || '%c': Clear result\n", RETURN_OPTION, CLEAR_OPTION);
    printf("Choose: ");
}

void BasicOpers(void) {
    CalcState calc = {0.0};
    double addup;

    while (true) {
        printf("Current result: %.*lf\n", GetSettings()->decimals_show, calc.result);

        PrintPrompt();
        char choice = GetUserChoice();

        if (choice == RETURN_OPTION) return;

        if (choice == CLEAR_OPTION) {
            calc.result = 0;
            continue;
        }

        if (!GetNumber(&addup)) {
            continue;
        }

        RunBasicOps(&calc, choice, addup);
    }
}