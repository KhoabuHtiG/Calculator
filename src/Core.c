#include "../include/Core.h"

Settings set;

char *menu[] = {"---Menu---", "1. Basic Operators", "2. Generate Random Number"};
int menuLength = sizeof(menu) / sizeof(menu[0]);

void PrintMenu() {for (int i = 0; i < menuLength; i++) printf("%s\n", menu[i]);}
Settings* GetSettings() {
    return &set;
}

void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void WaitForEnter() {
    printf("Enter to continue...\n");
    while (getchar() != '\n') {}
    while (getchar() != '\n') {}
}

bool GetData() {
    FILE *settingsFile = fopen("../src/Settings.txt", "r");

    if (!settingsFile) {
        printf("Error: Cannot open file.\n");
        return false;
    }

    char buffer[256];
    bool foundSomething = false;

    while (fgets(buffer, sizeof(buffer), settingsFile)) {
        int decimals;
        int confirm_quit_temp;

        if (sscanf(buffer, "decimals_places = %d", &decimals) == 1) {
            set.decimals_show = decimals;
            foundSomething = true;
            continue;
        }

        if (sscanf(buffer, "confirm_quit = %d", &confirm_quit_temp) == 1) {
            set.confirm_quit = (confirm_quit_temp == 1);
            foundSomething = true;
            continue;
        }

        printf("Error: Invalid format in Settings.txt\n");
        fclose(settingsFile);
        return false;
    }

    fclose(settingsFile);

    if (!foundSomething) {
        printf("Error: Settings.txt is empty\n");
        return false;
    }

    return true;
}

bool SaveSettings() {
    FILE *settingsFile = fopen("../src/Settings.txt", "w");

    if (!settingsFile) {
        printf("Error: Cannot save to Settings.txt\n");
        return false;
    }

    fprintf(settingsFile, "decimals_places = %d\n", set.decimals_show);
    fprintf(settingsFile, "confirm_quit = %d\n", set.confirm_quit);

    fclose(settingsFile);
    return true;
}