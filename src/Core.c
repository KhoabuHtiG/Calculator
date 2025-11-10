#include "../include/Core.h"

struct Settings set;

char *menu[] = {"---Menu---", "1. Basic Operators", "2. Generate Random Number"};
int menuLength = sizeof(menu) / sizeof(menu[0]);

void PrintMenu() {for (int i = 0; i < menuLength; i++) printf("%s\n", menu[i]);}

void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

bool GetData() {
    FILE *settingsFile = fopen("Settings.txt", "r");

    if (!settingsFile) {
        printf("Error: Cannot open file.\n");
        return false;
    }

    char buffer[256];
    

    fclose(settingsFile);
    return true;
}