This is the Programme for the famous Sudoku game,
which generally eats our mind.

Download the game in your system:

You can use make on terminal to set the game to start.

Firstly,set your admin login.
register normally with userid:'admin'
set password what you want.

Its self guided from there onwards.
some Features:Multiple-people can play this game.
the other feature about this game is that:
you can save results from where you left off.
start a new game.
You even have leaderboard.









From programmers point of view:

The following game is divided into 3 files:
1. main.c
This interacts with the player,guides him through the game and receives input and prints output.
This game has multiplayer mode and has leader board as well,meaning players are arranged in as per badges.
2. header.h
This file consists of all definitions.

3.function.c
This is file that comprises of several functions:

int is_sudoku_full(int mat[SIZE][SIZE]);    
This function checks if the sudoku is full, indicating if the game is completed or not.

void printSudoku(int puzzle[SIZE][SIZE]);   
This function prints the sudoku puzzle in a way the user see and enjoy with the grid.

int isValid(int puzzle[SIZE][SIZE], int row, int col, int num);  
This function checks if the number entered in a missing block is valid

int solveSudoku(int puzzle[SIZE][SIZE]);    
This function is beautiful recursive function, it solves the sudoku given to it. Must see

int generateSudoku(int puzzle[SIZE][SIZE],int difficulty);  
This function generates sudokus for the user to solve randomly.

int check_user(FILE *details,user person);
This funtion checks if the user, if already registered with us not.

void input(int solve[SIZE][SIZE]);
Takes input from the user and then solves the given sudoku.

void sort_by_num(FILE* sud);
Sorts playeres in the details file based on the badges earned.

void display_details(FILE *details);
Displays the details of players registered with the game.

void display_details_for_admin(FILE* details);
Displays special details(all details) to the admin.
