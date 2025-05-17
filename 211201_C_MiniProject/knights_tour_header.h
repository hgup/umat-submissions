#include <stdio.h>

#define XSIZE 8
#define YSIZE 8

void print_board(int board[YSIZE][XSIZE], int knightX, int knightY);
int valid(int board[YSIZE][XSIZE], int x, int y);
int solve_board(int board[YSIZE][XSIZE], int x, int y, int n);
int compar(const void *a, const void *b);
void mainKT();
