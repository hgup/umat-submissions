#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Helper function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Helper function to print tokens (for debugging)
void printToken(Token token) {
    printf("Token: Type=%d, Value=%s\n", token.type, token.value);
}

// Function to get the next token from the input string
Token getNextToken(const char* input, int* currentPosition) {
    Token token;
    token.value[0] = '\0';  // Initialize token value as an empty string

    // Skip whitespace characters
     while (isspace(input[*currentPosition])) {
        (*currentPosition)++;
    }

     // Check for end of input
    if (input[*currentPosition] == '\0') {
        token.type = END_OF_INPUT;
        return token;
    }

    // Check for numbers
   if (isdigit(input[*currentPosition]) || input[*currentPosition] == '.') {
        int i = 0;
        while (isdigit(input[*currentPosition]) || input[*currentPosition] == '.') {
            token.value[i++] = input[(*currentPosition)++];
        }
        token.value[i] = '\0';
        token.type = NUMBER;
        return token;
   }
    // Check for operators
     else if (isOperator(input[*currentPosition])) {
        token.value[0] = input[(*currentPosition)++];
        token.value[1] = '\0';
        token.type = OPERATOR;
        return token;
    } 
    // Check for parentheses
   else if (input[*currentPosition] == '(') {
        token.value[0] = input[(*currentPosition)++];
        token.value[1] = '\0';
        token.type = OPEN_PAREN;
        return token;
    } else if (input[*currentPosition] == ')') {
        token.value[0] = input[(*currentPosition)++];
        token.value[1] = '\0';
        token.type = CLOSE_PAREN;
        return token;
    }
    // Handle unrecognized characters
    else {
        token.type = ERROR;
        fprintf(stderr, "Error: Invalid character in infix expression\n");
            exit(EXIT_FAILURE);
    }
}
