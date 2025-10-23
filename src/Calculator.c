#include "../include/Calculator.h"

int result = 0, addup;

void getNumber() {
    printf("Enter your number: ");
    scanf("%d", &addup);
}

void basicOps() {
    char oper;
    printf("Current result: %d\n", result);

    while (1) {
        printf("Operators: '+', '-', '*', '/' || 'r': Return to main menu || 'c': Clear result\n");
        printf("Choose: ");
        scanf(" %c", &oper);

        switch (oper) {
            case '+':
                getNumber();

                result += addup;
                printf("Current result: %d\n", result);

                break;
            case '-':
                getNumber();

                result -= addup;
                printf("Current result: %d\n", result);

                break;
            case '*':
                getNumber();

                result *= addup;
                printf("Current result: %d\n", result);

                break;
            case '/':
                getNumber();

                result /= addup;
                printf("Current result: %d\n", result);

                break;
            case 'r':
            case 'R':
                return;
            case 'c':
            case 'C':
                result = 0;
                printf("Current result: %d\n", result);

                break;
            default:
                printf("Invalid operator. Please try again\n");
                break;
        }
    }
}