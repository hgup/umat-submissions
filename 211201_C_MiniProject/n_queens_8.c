#include <stdio.h>
#include <stdbool.h>

#include "n_queens_header.h"

//prints the solution and writes to the file as well
void printSolution_nq(int board[N][N]) {

    FILE *outputFile = fopen("n_queens.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file for writing.\n");
        return; 
    } 

    printf("\n");

    //the top border
    printf("┌");
    for (int i = 0; i < N - 1; i++) {
        printf("───┬");
    }
    printf("───┐\n");

    //printing out each of the rows
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("│");
            if (board[i][j] == 1)
                printf(" %d ", j + 1); //the queen's no.
            else
                printf(" x "); //empty cells
        }
        printf("│\n");

        //for border between two rows
        if (i < N - 1) {
            printf("├");
            for (int j = 0; j < N - 1; j++) {
                printf("───┼");
            }
            printf("───┤\n");
        }
    }

    //the bottom border
    printf("└");
    for (int i = 0; i < N - 1; i++) {
        printf("───┴");
    }
    printf("───┘\n");
    
    //writing the output to a file - similar procedure as writing to the console
    fprintf(outputFile, "\n");

    fprintf(outputFile, "┌");
    for (int i = 0; i < N - 1; i++) {
        fprintf(outputFile, "───┬");
    }
    fprintf(outputFile, "───┐\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(outputFile, "│");
            if (board[i][j] == 1)
                fprintf(outputFile, " %d ", j + 1);
            else
                fprintf(outputFile, " x ");
        }
        fprintf(outputFile, "│\n");

        if (i < N - 1) {
            fprintf(outputFile, "├");
            for (int j = 0; j < N - 1; j++) {
                fprintf(outputFile, "───┼");
            }
            fprintf(outputFile, "───┤\n");
        }
    }

    fprintf(outputFile, "└");
    for (int i = 0; i < N - 1; i++) {
        fprintf(outputFile, "───┴");
    }
    fprintf(outputFile, "───┘\n");

    //closing the file
    fclose(outputFile);
}

//checks if a queen can be placed on board[row][col]
bool isSafe_nq(int board[N][N], int row, int col) {
    int i, j;

    //check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    //check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    //check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

//recursive function to solve N-Queens problem
bool solveNQUtil(int board[N][N], int col) {
    //base condition - if all queens are placed then return true
    if (col >= N)
        return true;

    //consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        //checks if the queen can be placed on board[i][col]
        if (isSafe_nq(board, i, col)) {
            //places this queen in board[i][col]
            board[i][col] = 1;

            //now go back recursively
            if (solveNQUtil(board, col + 1))
                return true;

            //if placing queen in board[i][col] doesn't lead to a solution then remove queen from board[i][col]
            board[i][col] = 0; //basically BACKTRACKING!
        }
    }

    //If the queen cannot be placed in any row in this column col, then return false - NO SOLUTION
    return false;
}

//solves the N-Queens problem using Backtracking.
void solveNQ() {
    int board[N][N] = {0};

    //user's input - starting position of the first queen from the user
    int start_row;
    printf("Enter the row index (0 to %d) to place the first queen: ", N - 1);
    scanf("%d", &start_row);

    if (start_row < 0 || start_row >= N) {
        printf("Invalid input. Please enter a row index between 0 and %d.\n", N - 1);
        return;
    }

    board[start_row][0] = 1; //placing the first queen at the given row - based on the user's input

    if (solveNQUtil(board, 1) == false) {
        printf("No solution exists for the given starting position.\n");
        return;
    }

    printSolution_nq(board);
}
