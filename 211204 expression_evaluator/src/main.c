#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluator.h"
#include "parser.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <infix_expression>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *infixExpression = argv[1];
    char postfixExpression[MAX_EXPRESSION_LENGTH]; 

    // Convert infix expression to postfix
    infixToPostfix(infixExpression, postfixExpression);

    // Evaluate the postfix expression
    double result = evaluatePostfix(postfixExpression);

    printf("Result: %.2lf\n", result);

    return EXIT_SUCCESS;
}
