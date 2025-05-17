#ifndef EVALUATOR_H
#define EVALUATOR_H

// Include necessary headers
#include "parser.h"
#include "lexer.h" 


typedef struct {
    int top;
    double items[MAX_SIZE];
} eStack;

void epush(eStack *stack, double item);
double epop(eStack *stack);


// Function to evaluate a postfix expression
double evaluatePostfix(const char *postfixExpression);

#endif  // EVALUATOR_H
