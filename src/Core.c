#include "../include/Core.h"

Settings set;

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
    FILE *settingsFile = fopen("../src/Settings.txt", "r");

    if (!settingsFile) {
        printf("Error: Cannot open file.\n");
        return false;
    }

    char buffer[256];

    if (fgets(buffer, sizeof(buffer), settingsFile) == NULL) {
        printf("Error: Settings.txt is empty\n");
        fclose(settingsFile);
        return false;
    }

    int decimals;
    if (sscanf(buffer, "decimals_places = %d", &decimals) == 1) {
        set.decimals_show = decimals;
    } else if (sscanf(buffer, "%d", &decimals) == 1) {
        set.decimals_show = decimals;
    } else {
        printf("Error: Invalid format in Settings.txt\n");
        fclose(settingsFile);
        return false;
    }

    printf("Decimals places: %d", set.decimals_show);

    fclose(settingsFile);
    return true;
}