#pragma once
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    int decimals_show;
} Settings;

void PrintMenu();
void ClearScreen();
bool GetData();
bool SaveSettings();
Settings* GetSettings();