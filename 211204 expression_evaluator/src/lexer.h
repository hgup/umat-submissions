#ifndef LEXER_H
#define LEXER_H


typedef enum {
    NUMBER,
    OPERATOR,
    OPEN_PAREN,
    CLOSE_PAREN,
    END_OF_INPUT,
    ERROR
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

void printToken(Token token);
int isOperator(char ch);

Token getNextToken(const char* input, int* currentPosition);

#endif  // LEXER_H
