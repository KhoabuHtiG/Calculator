#include "../include/Execute.h"
#include "../include/Format.h"
#include "../include/Calculator.h"
#include "../include/Core.h"

void Execute(const char option) {
    switch (option) {
        case '1':
            ClearScreen();
            BasicOps();
            break;
        case '2':
            printf("%d\n", GenerateRandomNumber());
            break;
    }
}