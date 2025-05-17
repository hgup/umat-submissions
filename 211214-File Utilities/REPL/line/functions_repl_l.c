#include "header_repl_l.h"
#include <stdio.h>
#include <stdlib.h>

void replaceLine(int lineNumber, const char *newLine, const char *filename) {
    FILE *file;
    FILE *tempFile;
    char line[100];
    int count = 0;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Open a temporary file
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read lines from the original file and copy to temporary file,
    // replacing the specified line with the new line
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == lineNumber) {
            fprintf(tempFile, "%s\n", newLine);
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    // Close files
    fclose(file);
    fclose(tempFile);

    // Remove original file
    remove(filename);

    // Rename temporary file as the original file
    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming file");
        exit(EXIT_FAILURE);
    }

    printf("Line replaced successfully!\n");
}
