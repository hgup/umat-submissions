#include <stdio.h>

#include "knights_tour_header.h"
#include "n_queens_header.h"

int main() {
  int choice = 0;

  do {
       printf("Which Game Would You Like To Play? \n"); printf("\n");
       printf("1. Knight's Tour \n2. N Queens \n3. Quit \n");
       scanf("%d", &choice); printf("\n");
       switch (choice) {
        case 1:
          printf("Your Choice is 1. Knight's Tour \n");
          mainKT();
          break;
        case 2:
          printf("Your Choice is 2. N Queens \n");
          solveNQ();
          break;
        case 3:
          printf("Your Choice is 3. Quit \n");
          printf("Bye Bye! \n");
          break;
        default:
          printf("Invalid Option! Please Try Again!\n");
        }
        printf("------------------------------------------------------------------\n");
        printf("\n");
  } while (choice != 3);
  return 0;
}
