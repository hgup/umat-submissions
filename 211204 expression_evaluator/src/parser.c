#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // Lower precedence for non-operators
}

// Function to push an item onto the stack
void push(Stack *stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(Stack *stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

void infixToPostfix(const char *infixExpression, char *postfixExpression) {
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;
    char dummy; // Dummy variable to hold discarded pop value


    while (infixExpression[i] != '\0') {
        Token token = getNextToken(infixExpression, &i);

        if (token.type == NUMBER) {
            strcpy(postfixExpression + j, token.value);
            j += strlen(token.value);
            postfixExpression[j++] = ' '; // Add space after number
        } else if (token.type == OPERATOR) {
            while (stack.top >= 0 && precedence(token.value[0]) <= precedence(stack.items[stack.top])) {
                postfixExpression[j++] = pop(&stack);
                postfixExpression[j++] = ' ';
            }
            push(&stack, token.value[0]);
        } else if (token.type == OPEN_PAREN) {
            push(&stack, '(');
        } else if (token.type == CLOSE_PAREN) {
            while (stack.top >= 0 && stack.items[stack.top] != '(') {
                postfixExpression[j++] = pop(&stack);
                postfixExpression[j++] = ' ';
            }
            if (stack.top >= 0 && stack.items[stack.top] == '(') {
                dummy=pop(&stack); // Discard '('
            } else {
                fprintf(stderr, "Error: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Pop remaining operators from stack
    while (stack.top >= 0) {
        if (stack.items[stack.top] == '(') {
            fprintf(stderr, "Error: Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfixExpression[j++] = pop(&stack);
        postfixExpression[j++] = ' ';
    }

    postfixExpression[j] = '\0'; // Null-terminate the postfix expression
  //  printf("%s\n",postfixExpression);
}
