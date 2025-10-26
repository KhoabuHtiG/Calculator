#include "../include/Calculator.h"
#include "../include/Format.h"

double result = 0, addup;

void GetNumber() {
    printf("Enter your number: ");
    scanf("%lf", &addup);
}

void BasicOps() {
    char oper;
    printf("Current result: %lf\n", result);

    while (1) {
        printf("Operators: '+', '-', '*', '/' || 'r': Return to menu || 'c': Clear result\n");

        printf("Choose: ");
        scanf(" %c", &oper);

        switch (oper) {
            case 'c':
                result = 0;
                printf("Current result: %lf\n", result);

                break;
            case 'r':
                return;
            case '+':
                GetNumber();

                Add(&result, addup);
                printf("Current result: %lf\n", result);

                break;
            case '-':
                GetNumber();

                Subtract(&result, addup);
                printf("Current result: %lf\n", result);

                break;
            case '*':
                GetNumber();

                Multiply(&result, addup);
                printf("Current result: %lf\n", result);

                break;
            case '/':
                GetNumber();

                Divided(&result, addup);
                printf("Current result: %lf\n", result);

                break;
            default:
                printf("Invalid operator. Please try again\n");
                break;
        }
    }
}