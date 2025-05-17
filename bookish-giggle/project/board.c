/*The main function of the chess game.*/
#include"header.h"
#include<stdio.h>
// #include<conio.h>

int main(){
    do{
        switch(mainMenu()){
            case 0:
                    loadgame();
                    break;
            case 1:
                    controls();
                    break;
            case 2:
                    exitYN();
                    break;
        }
    }while(1);

    /*char mat[8][8];
    printf("\e[1;H\e[2J");
    matrix(mat);
    startGame(mat);
    display();
    while(1){
        printf("The player1's turn to play please selete the pown to move\n:");
        input(mat);
        //clrscr();
        printf("\e[1;H\e[2J");
        display();

        printf("The player 2's turn to play, please selete the pown to move\n");
        input(mat);
        //clrscr();
        printf("\e[1;H\e[2J");
        display();
    }*/
        return 0;
}