#include "evaluator.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Function to epush an item onto the stack
void epush(eStack *stack, double item) {
    if (stack->top >= MAX_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to epop an item from the stack
double epop(eStack *stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}
// Function to evaluate a postfix expression
double evaluatePostfix(const char *postfixExpression) {
    eStack stack;
    stack.top = -1;

    Token token;

    // Initialize the current position for tokenization
    int currentPosition = 0;

    while ((token = getNextToken(postfixExpression, &currentPosition)).type != END_OF_INPUT) {
        if (token.type == NUMBER) {
            epush(&stack, atof(token.value)); // Convert token to double and epush onto stack
        } else if (token.type == OPERATOR) {
            if (stack.top < 1) {
                fprintf(stderr, "Error: Invalid postfix expression\n");
                exit(EXIT_FAILURE);
            }
            double operand2 = epop(&stack);
            double operand1 = epop(&stack);
            //diagonosis
            //printf("%lf:%lf\n",operand1,operand2);
           

            switch (token.value[0]) {
                case '+':
                    epush(&stack, operand1 + operand2);
                    break;
                case '-':
                    epush(&stack, operand1 - operand2);
                    break;
                case '*': 
                    epush(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        fprintf(stderr, "Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    epush(&stack, operand1 / operand2);
                    break;
                default:
                    fprintf(stderr, "Error: Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Error: Invalid token in postfix expression\n");
            exit(EXIT_FAILURE);
        }
    }

    if (stack.top != 0) {
        fprintf(stderr, "Error: Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }

    return epop(&stack);
}
