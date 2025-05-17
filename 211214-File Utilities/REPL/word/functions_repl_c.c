#include "header_repl_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalpha function

#define BUFFER_SIZE 1000

/**
 * Replace all occurrences of a given word in a string.
 */
void replaceAll(char *str, const char *oldWord, const char *newWord) {
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    // Fix: If oldWord and newWord are the same, it goes into an infinite loop
    if (!strcmp(oldWord, newWord)) {
        return;
    }

    /*
     * Repeat till all occurrences are replaced.
     */
    while ((pos = strstr(str, oldWord)) != NULL) {
        // Check if the found occurrence is a whole word
        if ((pos == str || !isalpha(*(pos - 1))) && (!isalpha(*(pos + owlen)) || *(pos + owlen) == '\0')) {
            // Backup current line
            strcpy(temp, str);

            // Index of the current found word
            index = pos - str;

            // Terminate str after the word found index
            str[index] = '\0';

            // Concatenate str with the new word
            strcat(str, newWord);

            // Concatenate str with remaining words after
            // old word found index.
            strcat(str, temp + index + owlen);
        } else {
            // Move forward in the string
            str += (pos - str) + owlen;
        }
    }
}
