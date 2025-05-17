#include "header_repl_l.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s linenumber \"string\" file\n", argv[0]);
        return -1;
    }

    int lineNumber = atoi(argv[1]);
    char *newLine = argv[2];
    char *filename = argv[3];

    replaceLine(lineNumber, newLine, filename);

    return 0;
}
