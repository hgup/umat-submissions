#include "header_repl_c.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <file_path> <old_word> <new_word>\n", argv[0]);
        return -1;
    }

    char *path = argv[1];
    char *oldWord = argv[2];
    char *newWord = argv[3];

    FILE *fPtr;
    FILE *fTemp;
    char buffer[BUFFER_SIZE];

    /*  Open all required files */
    fPtr = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w");

    /* fopen() returns NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL) {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }

    /*
     * Read line from source file and write to destination
     * file after replacing given word.
     */
    while (fgets(buffer, BUFFER_SIZE, fPtr) != NULL) {
        // Replace all occurrences of word from the current line
        replaceAll(buffer, oldWord, newWord);

        // After replacing write it to the temp file.
        fputs(buffer, fTemp);
    }

    /* Close all files to release resources */
    fclose(fPtr);
    fclose(fTemp);

    /* Delete the original source file */
    remove(path);

    /* Rename the temp file as the original file */
    rename("replace.tmp", path);

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.\n", oldWord, newWord);

    return 0;
}
