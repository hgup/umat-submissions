#include <stdio.h>
#include <stdbool.h>

#define N 8

void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool solveNQUtil(int board[N][N], int col);
void solveNQ();
