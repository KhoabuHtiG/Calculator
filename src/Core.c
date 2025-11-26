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
    printf("Enter to continue...");
    while (getchar() != '\n');
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

    while (fgets(buffer, sizeof(buffer), settingsFile)) {
        int decimals;
        bool comfirm_quit;

        if (sscanf(buffer, "decimals_places = %d", &decimals) == 1) {
            set.decimals_show = decimals;
            continue;
        } 
        
        if (sscanf(buffer, "comfirm_quit = %d", &comfirm_quit) == 1) {
            if (comfirm_quit == 1) {
                set.comfirm_quit = true;
            } else set.comfirm_quit = false;

            continue;
        }

        printf("Error: Invalid format in Settings.txt\n");
        fclose(settingsFile);

        return false;
    }

    fclose(settingsFile);
    return true;
}

bool SaveSettings() {
    FILE *settingsFile = fopen("../src/Settings.txt", "w");

    if (!settingsFile) {
        printf("Error: Cannot save to Settings.txt\n");
        return false;
    }

    fprintf(settingsFile, "decimals_places = %d\n", set.decimals_show);

    fclose(settingsFile);
    return true;
}