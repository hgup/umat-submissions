#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header_srep.h"

#define Rd    "\e[1;91m"
#define RESET   "\e[0m"

// Global variables
extern int matches; // Printing no. of matched Lines counter
extern int lineNumbers; // Line number checker i.e -n for functioning

// Highlight all occurrences of the pattern given by the user in a line and print filename if there's a match
void printHighlighted(const char *line, const char *pattern, const char *filename, int exactWord) {
    const char *found = line;
    int print = 0; // Printing counter
    static int line_number = 0; // Line counter
    
    // Tokenize the pattern by '|' and search for each word individually
    char *mutablePattern = strdup(pattern); // Create a mutable copy of the pattern
    char *word = strtok(mutablePattern, "|");
    
    while (word != NULL) {
        const char *wordStart = found;
        
        // Search for the current word in the line (case-insensitive)
        while ((found = strstr(found, word)) != NULL) {
            // Check if the found word matches exactly if -w option is provided
            if (!exactWord || (exactWord && ((found == line || !isalpha(found[-1])) && (found[strlen(word)] == '\0' || !isalpha(found[strlen(word)]))))) {
                if (print == 0) {
                    matches++;
                    printf("\e[38;5;208m%s: \e[0m", filename); // Print filename
                    if (lineNumbers == 1)
                        printf("\e[32m%d:\e[0m", line_number);
                    print = 1;
                }
                
                // Print the part of the line before the found word
                fwrite(wordStart, 1, found - wordStart, stdout);
                fputs(Rd, stdout); // Start highlighting
                fwrite(found, 1, strlen(word), stdout); // Print the word
                fputs(RESET, stdout); // Reset color
                found += strlen(word); // Move to the next position after the found word
                wordStart = found; // Update the start position for the next search
            } else {
                found++; // Move to the next position after the found word
            }
        }
        
        // Print the remaining part of the line
        if (wordStart != NULL)
            fputs(wordStart, stdout);
        
        // Move to the next word in the pattern
        word = strtok(NULL, "|");
        
        // Reset the found pointer and move to the beginning of the line
        found = line;
    }
    
    free(mutablePattern); // Free the allocated memory for the mutable copy of the pattern
    line_number++;
}
