#include <stdio.h>

#define SIZE 9

struct user{
    char name[20];
    int password;
    int number;
};
typedef struct user user;

// Function prototypes
int is_sudoku_full(int mat[SIZE][SIZE]);
void printSudoku(int puzzle[SIZE][SIZE]);
int isValid(int puzzle[SIZE][SIZE], int row, int col, int num);
int solveSudoku(int puzzle[SIZE][SIZE]);
int generateSudoku(int puzzle[SIZE][SIZE],int difficulty);
int check_user(FILE *details,user person);
void input(int solve[SIZE][SIZE]);
void sort_by_num(FILE* sud);
void display_details(FILE *details);
void display_details_for_admin(FILE* details);
