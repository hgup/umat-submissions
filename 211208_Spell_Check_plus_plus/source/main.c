#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include "dictionary.h"
#include "dictionary.c"
#define LEN 5

int main(int argc, char* argv[]){
    
    if (argc != 2) {
        printf("\nEnter a word while executing the program.\n");
        return 1;
    }
    
    char *word[LEN];
    for (int i = 0; i < LEN; i++) {
        word[i] = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));
        if (word[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(word[0], argv[1]);
    }

    int num; bool loaded; // Load dictionary
    loaded = load("/workspaces/C-programming/Dictionary_file/Dictionary.txt");
    if (!loaded){
        printf("Could not load dictionary.\n");
        return 1;
    }

    if (check(word[0])) // Check the word
        printf("\n%s is a correct spelling.\n", word[0]);
    else {
        printf("\n%s is a wrong spelling or not present in the dictionary\n", word[0]);
        correctit(&word[0]);
    }
    
    free(word[0]); // Free allocated memory
    unload(); // Unload dictionary
    return 0;
}