/* The header library for the chess game.*/
#include<stdio.h>


	#include <stdlib.h>
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include<string.h>
	//Linux Constants

	//Controls (arrow keys for Ubuntu) 
	#define UP_ARROW (char)'A' //Originally I used constants but borland started giving me errors, so I changed to #define - I do realize that is not the best way.
	#define LEFT_ARROW (char)'D'
	#define RIGHT_ARROW (char)'C'
	#define DOWN_ARROW (char)'B'

	#define ENTER_KEY 10
void controls(void);
void exitYN(void);
int mainMenu(void);
void startGame(char mat[8][8]);
void display(void);
void matrix(char mat[8][8]);
int P_soilder(int r, int c, int i, int j,char mat[8][8]);
int p_soilder(int r, int c, int i, int j,char mat[8][8]);
int R_rock(int r,int c, int i, int j, char mat[8][8]);
int r_rock(int r,int c, int i, int j,char mat[8][8]);
int B_bishop(int r, int c, int i, int j, char mat[8][8]);
int b_bishop(int r, int c, int i, int j, char mat[8][8]);
int Q_queen(int r, int c, int i, int j, char mat[8][8]);
int q_queen(int r, int c, int i, int j, char mat[8][8]);
int N_knights(int r,int c, int i, int j, char mat[8][8]);
int n_knights(int r,int c, int i, int j, char mat[8][8]);
void input(char mat[8][8]);
int upper_check(char mat[8][8]);
int lower_check(char mat[8][8]);
void loadgame(void);
void gotoxy(int x,int y);
int menuSelector(int x, int y, int yStart);
char waitForAnyKey(void);
void controls(void);
char getch(void);
int kbhit(void);