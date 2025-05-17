//Written by Omkar Reddy
//Sudoku solving using Backtracking


//setting up the libraries tto be used
# include "header.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <time.h> 




// Function to generate a Sudoku puzzle
int generateSudoku(int puzzle[SIZE][SIZE],int difficulty)
    {int i,row,col,num;
    int numToRemove;
    srand(time(NULL)); 
        // Initialize puzzle with zeros
    for (i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) {
                puzzle[i][j] = 0;
            }
        }
        //creating a set of randomness before the start itself
        //setting 15 random integers in the puzzle in the beginning and then solving it.
        for(i=0;i<15;i++)
        {
            row=rand()%SIZE;
            col=rand()%SIZE;
            if (puzzle[row][col]==0)
            {num=rand()%SIZE+1;
            if(isValid(puzzle,row,col,num))
            puzzle[row][col]=num;
            }
        }
        // Solve the puzzle
        if (!solveSudoku(puzzle))
            return 0;
        // Remove some numbers to create a puzzle
        if (difficulty==1)
        numToRemove=30;
        if (difficulty==2)
        numToRemove=45;
        if (difficulty==3)
        numToRemove=60;
        if (difficulty==4)
        numToRemove=67;

        while (numToRemove > 0) {
            row = rand() % SIZE;
            col = rand() % SIZE;
            if (puzzle[row][col] != 0) {
                puzzle[row][col] = 0;
                numToRemove--;
            }
        }
    return 1;
    }

// Function to solve the Sudoku puzzle using backtracking 
//A beautiful algorithm to solve such a big problem
int solveSudoku(int puzzle[SIZE][SIZE]) 
    {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (puzzle[row][col] == 0)
                    { // Empty cell found
                    for (int num = 1; num <= SIZE; num++) {
                        if (isValid(puzzle, row, col, num)) {
                            puzzle[row][col] = num;
                            if (solveSudoku(puzzle))
                                {
                                return 1; 
                                // Puzzle solved successfully
                            }
                            puzzle[row][col] = 0; 
                            // Backtrack
                        }
                    }
                    return 0; 
                    
                    // No valid number found
                }
            }
        }
        return 1;
            // Puzzle solved (the initial puzzle inputed,if 1 our main sudoku is solved)
    }





int is_sudoku_full(int mat[SIZE][SIZE])
    {int i,j;
        for (i=0;i<SIZE;i++)
        {
            for (j=0;j<SIZE;j++)
            {
                if (mat[i][j]==0)
                return 0;
            }
        }

        return 1;
    }

int check_user(FILE *details,user person)
    {user check;
    rewind(details);
        while(!feof(details))
        {
        fread(&check,sizeof(user),1,details);
        if (strcmp(check.name,person.name)==0)
        {if (check.password==person.password)
        return 1;
        else
        {
        return 2;
        }
        }
        }
        return 0;
    }

// Function to check if placing 'snum' at puzzle[row][col] is valid
int isValid(int puzzle[SIZE][SIZE], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num || puzzle[i][col] == num) {
            return 0; // Not valid
        }
    }

    // Check subgrid (3x3)
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0; // Not valid
            }
        }
    }

    return 1; // Valid
}

//Function to take input of a sudoku from the user;
void input(int solve[SIZE][SIZE])
{   int row,col,ans;
    int i,j;
    int alt;
    printf("\nENTER 0 WHERE A BLOCK IS EMPTY\n");
    for(i=0;i<SIZE;i++)
    {

    for (j=0;j<SIZE;j++)
    {   printf("\nEnter the row no %d,column no %d:",i+1,j+1);
        scanf("%d",&solve[i][j]);
    }
    }
    printf("You entered your sudoku");
    printf("\nThe following is the sudoku you entered:");
    printSudoku(solve);
    while(alt)
    {
    printf("Enter 1 to change if any blocks are entered wrong\nelse enter 0");
    scanf("%d",&alt);
    if (alt)
    {
        printf("\nPlease enter the row number where you wanna change the value of your sudoku:");
        scanf("%d",&row);
        printf("\nPlease enter the col number where you wanna change the value of your sudoku:");
        scanf("%d",&col);
        printf("\nEnter the value you wanna change:");
        scanf("%d",&ans);
        solve[row-1][col-1]=ans;
        printSudoku(solve);
    }
    }
    system("clear");
}

// Function to print the Sudoku puzzle
void printSudoku(int puzzle[SIZE][SIZE]) {
    printf("\n                                                                   1   2   3   4   5   6    7   8   9  \n");
    printf("                                                                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n                                                              ");
    for (int i = 0; i < SIZE; i++)
     {
        {printf("%d █",i+1);
        for (int j = 0; j < SIZE; j++) 
        {
            if (puzzle[i][j]==0 && (j==3||j==6))
               printf("█   ");
            else
              {if (puzzle[i][j]==0)
                printf("|   ");
               else
                 {
                  if (j==3||j==6)
                     printf("█ %d ", puzzle[i][j]);
                  else
                    printf("| %d ",puzzle[i][j]);
                 }
              } 
        }
        if(i==2||i==5)
        {
            printf("|█\n                                                                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n                                                              ");

        }
        else if(i!=8)
            printf("|█\n                                                                ---------------------------------------\n                                                              ");
        }
        
    }
    printf("|█\n                                                                ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}





//sort by details based on number of puzzles solved
void sort_by_num(FILE* sud)
{int count=0;
 int i,j;
user s;
rewind(sud);
while(fread(&s,sizeof(user),1,sud))
{
   count++;
}
rewind(sud);
user* pointer=(user*)malloc(sizeof(user)*count);
if (pointer)
  {fread(pointer,sizeof(user),count,sud);
  for (i=0;i<count-1;i++)
    {for (j=0;j<count-i-1;j++)
      {if ((pointer+j)->number < (pointer+j+1)->number)
        {s=*(pointer+j);
        *(pointer+j)=*(pointer+j+1);
        *(pointer+j+1)=s;
        }
      }
    }
  }
FILE *q=fopen("dummy","wb");
if (q)
 {fwrite(pointer,sizeof(user),count,q);
  fclose(q);
  remove("details");
  rename("dummy","details");
 }
}




//displaying the customer details
void display_details(FILE *details)
{printf("\nOur Top Players are:");
user s;
rewind(details);
printf("\n");
while (fread(&s,sizeof(user),1,details)==1)
{
 printf("Name of the player:%s\n",s.name);
 printf("Batches earned:%d\n",s.number);
 printf("\n");
}
}


//display the details for admin
void display_details_for_admin(FILE* details)
{printf("\nThe following are our Players:\n");
user s;
rewind(details);
printf("\n");
while (fread(&s,sizeof(user),1,details)==1)
{
 printf("Name of the player:%s",s.name);
 printf("\npassword:%d\n",s.password);
 printf("Batches earned:%d\n",s.number);
 printf("\n");
}
}