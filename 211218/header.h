#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

#define MAX_PLAYERNAME_LENGTH 500

struct FIFA2022 {
    int jerseynum;
    char playername[MAX_PLAYERNAME_LENGTH];
    int goals;
    char award[50];
};

void displayFIFA2022(struct FIFA2022 F);

void insertFIFA2022(FILE *file);

void deleteFIFA2022(FILE *file, char playername[MAX_PLAYERNAME_LENGTH]);

void selectionSort(struct FIFA2022 arr[], int n);

void sortFIFA2022Bygoals(FILE *file);

#endif

