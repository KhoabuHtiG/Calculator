#include "../include/Format.h"
#include "stdio.h"

int generateRandomNumber() {
    srand(time(NULL));
    int max, min;

    printf("Enter your min: ");
    scanf("%d", &min);

    printf("Enter your max: ");
    scanf("%d", &max);

    int result = rand() % (max - min + 1) + min;
    return result;
}