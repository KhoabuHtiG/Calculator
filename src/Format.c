#include "../include/Format.h"

int Add(double *x, double y) {return *x += y;}
int Subtract(double *x, double y) {return *x -= y;}
int Multiply(double *x, double y) {return *x *= y;}
int Divided(double *x, double y) {return *x /= y;}

int SquareRoot(double *x) {return *x = sqrt(*x);}

int GenerateRandomNumber() {
    srand(time(NULL));
    int max, min;

    printf("Enter your min: ");
    scanf("%d", &min);

    printf("Enter your max: ");
    scanf("%d", &max);

    int result = rand() % (max - min + 1) + min;
    return result;
}