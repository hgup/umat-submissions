#include <stdio.h>
#include <stdlib.h>

#include "knights_tour_header.h"

int moves[8][2] = {                                             //valid moves
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

void mainKT()
{
    int startRow, startCol, num_entries;
    
    //asking user for valid input
    do {
        printf("Enter the starting position of the knight (row col): ");
        num_entries = scanf("%d %d", &startRow, &startCol);

        //clears the input buffer in case of invalid input --- to avoid unnecessary behaviour
        while (getchar() != '\n');

        if (num_entries == 2 && startRow >= 0 && startCol >= 0 && startRow < YSIZE && startCol < XSIZE) { break; }
        else {
              printf("Please enter valid input! \n");
        }
    } while (1);
    
    int board[YSIZE][XSIZE] = {{0}};
    
    char* filename;
    //solve the Knight's tour problem. Start position - entered by the user
    if (solve_board(board, startCol, startRow, 1)) {
        print_board(board, startCol, startRow);
      }
    else
        printf("No solution.\n"); //incase of no solution

  //return 0;
}

void print_board(int board[YSIZE][XSIZE], int knightX, int knightY)
{
    FILE *file = fopen("knights.txt", "w"); //opening the file to write --- if we want to store all the solutions, then go for "a+" mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }  

    int x, y;
    printf("┌───┬───┬───┬───┬───┬───┬───┬───┐\n");  //for better visualization --- separators from the ASCII Characters

    for (y = 0; y < YSIZE; y++)
    {
        printf("│");
        for (x = 0; x < XSIZE; x++)
        {
            if (x == knightX && y == knightY)
                printf(" K │");
            else if (board[y][x] == 0)
                printf("    │");
            else
                printf(" %2d│", board[y][x]);  //%2d - setting minimum width of the output to 2 characters
        }
        printf("\n");
        if (y < YSIZE - 1) 
            printf("├───┼───┼───┼───┼───┼───┼───┼───┤\n");
    }
    printf("└───┴───┴───┴───┴───┴───┴───┴───┘\n");
    
    //print the same to the file
    fprintf(file, "\n");

    fprintf(file, "┌");
    for (int i = 0; i < XSIZE - 1; i++) {
        fprintf(file, "───┬");
    }
    fprintf(file, "───┐\n");

    for (int y = 0; y < YSIZE; y++) {
        fprintf(file, "│");
        for (int x = 0; x < XSIZE; x++) {
            if (x == knightX && y == knightY)
                fprintf(file, " K │");
            else if (board[y][x] == 0)
                fprintf(file, "    │");
            else
                fprintf(file, " %2d│", board[y][x]);
        }
        fprintf(file, "\n");
        if (y < YSIZE - 1)
            fprintf(file, "├───┼───┼───┼───┼───┼───┼───┼───┤\n");
    }
    fprintf(file, "└───┴───┴───┴───┴───┴───┴───┴───┘\n");

    fclose(file); //closing the file
}


int valid(int board[YSIZE][XSIZE], int x, int y)
{
    return x >= 0 && x < XSIZE && y >= 0 && y < YSIZE && board[y][x] == 0; //checking validity of the position
}

int compar(const void *a, const void *b)
{
    return ((int *)a)[0] - ((int *)b)[0];
}

int solve_board(int board[YSIZE][XSIZE], int x, int y, int n) 
{
    board[y][x] = n;
    if (n == XSIZE * YSIZE)
        return 1;

  //getting all the valid moves to count their "loneliness" --- for optimization 
    int i, j, valids[8][3];
    for (i = 0; i < 8; i++)
    {
        valids[i][0] = 0;
        valids[i][1] = x + moves[i][0];
        valids[i][2] = y + moves[i][1];
        if (valid(board, valids[i][1], valids[i][2]))
            for (j = 0; j < 8; j++)
                if (valid(board, valids[i][1] + moves[j][0],
                          valids[i][2] + moves[j][1]))
                    valids[i][0]++;
    }

    //sort each of the valid moves using the qsort() from stdlib
    qsort(&valids[0][0], 8, 3 * sizeof(int), &compar);
    for (i = 0; i < 8; i++)
        if (valid(board, valids[i][1], valids[i][2]) &&
            solve_board(board, valids[i][1], valids[i][2], n + 1))
            return 1;

    //on-reaching the dead-end
    board[y][x] = 0;
    return 0;
}
