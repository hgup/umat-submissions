#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header_srep.h"

#define Rd    "\e[1;91m"
#define RESET   "\e[0m"

// Global variables
int matches = 0; // Printing no. of matched Lines counter
int lineNumbers = 0; // Line number checker i.e -n for functioning

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <Pattern> <-option><File1> [<File2> ...] <-option>\n", argv[0]);
        return 1;
    }
    
    // To handle command line arguments like -i,-w,-c,-n in the grp command
    int ignoreCase = 0; // -i
    int countMatches = 0; // -c
    int exactWord = 0; // -w
    
    char *pattern = strdup(argv[1]); // Make a mutable copy of the search pattern
    char *word = pattern; // Use the mutable copy for strtok
    
    // Parsing command line arguments
    int i = 2;
    while (i < argc) {
        if (strcmp(argv[i], "-i") == 0) {
            ignoreCase = 1;
        } else if (strcmp(argv[i], "-c") == 0) {
            countMatches = 1;
        } else if (strcmp(argv[i], "-n") == 0) {
            lineNumbers = 1;
        } else if (strcmp(argv[i], "-w") == 0) {
            exactWord = 1;
        } else {
            break; // Found the search pattern, exit loop
        }
        i++;
    }
    
    i = 2; // Resetting the argument counter
    while (i < argc) {
        FILE *file = fopen(argv[i], "r");
        if (file != NULL) {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printHighlighted(buffer, word, argv[i], exactWord);
            }
            fclose(file);
            
            // -c
            if (countMatches) {
                printf("\033[038;5;206mNo. of matched Lines:%d\033[0m\n", matches);
                matches = 0;
            }
        }
        i++;
    }
    
    free(pattern); // Free the allocated memory for the mutable copy of the search pattern
    return 0;
}
