#include "header.h"

void displayFIFA2022(struct FIFA2022 F) {
    printf("Jersey Number: %d, Player Name: %s, Goals: %d, Award: %s\n", F.jerseynum, F.playername, F.goals, F.award);
}

void insertFIFA2022(FILE *file) {
    struct FIFA2022 F;

    printf("Enter Jersey Number: ");
    scanf("%d", &F.jerseynum);

    printf("Enter Player Name: ");
    scanf("%s", F.playername);

    printf("Enter Goals: ");
    scanf("%d", &F.goals);

    printf("Enter Award: ");
    scanf("%s", F.award);

    fseek(file, 0, SEEK_END);
    fwrite(&F, sizeof(struct FIFA2022), 1, file);

    printf("Inserted successfully.\n");
}

void deleteFIFA2022(FILE *file, char playername[MAX_PLAYERNAME_LENGTH]) {
    struct FIFA2022 F;
    FILE *temp;

    temp = fopen("temporary.txt", "wb+");
    if (temp == NULL) {
        printf("Error opening file.\n");
        fclose(temp);
        return;
    }

    rewind(file);
    while (fread(&F, sizeof(struct FIFA2022), 1, file) == 1) {
        if (strcmp(F.playername, playername) != 0) {
            fwrite(&F, sizeof(struct FIFA2022), 1, temp);
        }
    }

    rewind(temp);
    fclose(temp);
    fclose(file);
    remove("fifa.txt");
    rename("temporary.txt", "fifa.txt");

    printf("Record with player name %s deleted successfully.\n", playername);
    file = fopen("fifa.txt", "rb+");
}

void selectionSort(struct FIFA2022 arr[], int n) {
    int i, j, maxIndex;
    struct FIFA2022 temp;
    for (i = 0; i < n - 1; i++) {
        maxIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].goals > arr[maxIndex].goals) {
                maxIndex = j;
            }
        }
        // Swap the players
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

void sortFIFA2022Bygoals(FILE *file){
    struct FIFA2022 players[100];
    int count =0;
    rewind(file);
    while(fread(&players[count],sizeof(struct FIFA2022),1,file) ==1){
        count++;
    }
    selectionSort(players,count);
    rewind(file);
    fwrite(players,sizeof(struct FIFA2022),count,file);
}

