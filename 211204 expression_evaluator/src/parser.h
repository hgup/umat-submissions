#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

#define MAX_SIZE 100// Maximum size of the stack
#define MAX_EXPRESSION_LENGTH 100
// Structure for stack
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function prototypes for the stack operations
void push(Stack *stack, char item);
char pop(Stack *stack);

// Function prototypes for parser
int precedence(char op);
void infixToPostfix(const char *infixExpression, char *postfixExpression);

#endif  // PARSER_H
