//Written by Omkar Reddy
//A Complete Sudoku game developed as part of a mini project.

//TITLE:Sudoku solving using Backtracking

//Requirements;
# include <stdio.h>
# include <stdlib.h>
# include "header.h"
# include <stdlib.h>
# include <string.h>

//The main function

int main() {
//The initialisation of several variables,structures and file pointer to start with.
    char Admin[20]="admin";
    int puzzle[SIZE][SIZE];
    int process[SIZE][SIZE];
    int check=1;
    int check_1=1;
    int choice;
    int difficulty;
    int userchoice;
    user person;
    FILE *details;
    FILE* sud;
    int cond_2;
    int row;
    int col;
    int answer; 
//seeing if he is a new or old user
while(check_1)
{  
//Welcoming the user to your portal  
    system("clear");
    printf("\n\n\n                                                                    Welcome To The Sudoku Club                                           \n ");
    printf("\n  1.Enter (1):Register\n  2.Enter (2):Login to terminal\n  3.Enter (3):Admin_Access\n  4.Enter (4):TO EXIT\n");
    //getting to know if user is first time on our portal or not
    scanf("%d",&userchoice);
    //opening the details file to check and store user info
    details=fopen("details","a+b");



    //using a switch to change based on the choice made by the user
    switch (userchoice)
    {
    case 1:

       //collecting his name and password
       printf("\nPlease enter your username(all small letters,only first name):");     
       getchar();                                                                         
       gets(person.name);
       printf("\nPlease enter your password(5-digit):");
       scanf("%d",&person.password);

        //checking if our user has already logged in once before or not.
       if (check_user(details,person)==0)                                             
        {person.number=0;
        fwrite(&person,sizeof(user),1,details);
        printf("You are REGISTERED,ThankYou for joining us\nGenerate Your First sudoku.Press (1) to begin with:");
        fclose(details);
        check_1=0;
        }
       else
         {//informming that he is already our customer.
         printf("\n\n\nYour already our registered customer,No registration again.Press (2):");
         }
        break;



    case 2:
       //incase already a user allowing to login provided correct password.
       printf("\nPlease enter your username(all small letters,only first name):");       
       getchar();
       gets(person.name);
       printf("\nPlease enter your password(5-digit):");
       scanf("%d",&person.password);

       //checking the accurateness of the password and if first time using our game etc
       if(check_user(details,person)==0)
          //found out that not a user so again ask him to register
          printf("\nPlease Register and join to play the sudoku");  

       if (check_user(details,person)==2)
          //entered wrong password
          { printf("\nYou entered wrong password.");
             printf("Start from the beggining");
          }
       if (check_user(details,person)==1)
         {//allowing him in as all were right
         check_1=0;
        fclose(details);
         }
       break;
    


    case 3:
        //Meant for the admin to access the portal to see things  like badges and passwords of the users.
        int see=0;

        //BY DEFAULT THE ADMIN USERID IS: admin AND PASSWORD IS SET AT THE START BY REGISTERING AS ADMIN AND SETTING THE PASSWORD LIKE ANYOTHER USER.
        printf("\nPlease enter your Admin_name:");
        getchar();
        gets(person.name);
        printf("\nPlease enter your password(5-digit):");
        scanf("%d",&person.password);

        //checking his password just like the before.
        if (strcmp(Admin,person.name)==0)
        {if (check_user(details,person)==2)
            { printf("\nYou entered wrong password");
            printf("\nStart from the beggining");
            }
        if (check_user(details,person)==0)
            printf("\nPlease register through the normal portal");
        if (check_user(details,person)==1)
            {printf("\nWelcome you back!!!\n");
            display_details_for_admin(details);
            fclose(details);
            }


        }
        //warning if other userid tried admin access
        else
        printf("\nDONT TRY ACCESSING THE ADMIN...REPERCUSSIONS ARE HEAVY.");
        printf("\nEnter a KEY to EXIT\n");
        scanf("%d",&see);
        break;

    case 4:
        //if the user wants to quit,providing him an avenue.
        system("clear");
        return 0;
        break;

    default:
        break;
    }
}








//The main interface with all features.
system("clear");
printf("\nWelcome,%s\n",person.name);

while(check)
{
    printf("\n1.Enter (1):generate a new sudoku puzzle.\n2.Enter (2)continue to solve the existing sudoku puzzle.\n3.Enter (3):know the solution of the current game\n4.Enter (4):Give a Puzzle for the computer to solve\n5.Enter (5):check the leaderboard.\n6.Enter (6):clear the termianal.\n7.Enter (7):EXIT THE GAME.\n");
    scanf("%d",&choice);
    system("clear");

    switch (choice)
    {      


    case 1:           
            //generating a new sudoku puzzle for our user                                                                  
            printf("\nHey %s Please select the difficulty:\n1.Easy \n2.Medium \n3.High Medium \n4.Genius\n",person.name);
            scanf("%d",&difficulty);
            int d=generateSudoku(puzzle,difficulty);
            if (d)
            {
            printf("\nALL THE BEST\nHere Goes Your Sudoku Puzzle:\n");
            printSudoku(puzzle);
            //collecting the gen sudoku and storing it in a file on his name
            sud=fopen(person.name,"w+b");                                                                           
            rewind(sud);
            fwrite(puzzle,sizeof(int),SIZE*SIZE,sud);
            fclose(sud);
            break;
            }
            else
              printf("\nFound some error while generating...Try Again");
            break;


    case 2:     
            //allowing th user to solve the existing puzzle on his name.
            sud=fopen(person.name,"r+b");                                                                                 
            if (!sud)
            {//if a fellow did not gen his sudoku.ask him to gen it.
                printf("\nPlease generate your fist sudoku to solve one.Press(1)\n");
                break;
            }
            
            //copying a sudoku into the puzzle
            rewind(sud);
            fread(puzzle,sizeof(int),SIZE*SIZE,sud);                                                                    
            rewind(sud);

            //making a copy of sudoku and solving it for comparison.
            fread(process,sizeof(int),SIZE*SIZE,sud);                                                                   
            solveSudoku(process);

            //getting in to the solving mode.
            cond_2=1;
            while (cond_2)
                    {//screen cleanedup for the game and updated after every entry
                    system("clear");    
                    //giving the user a chance to exit if he wishes.                                                                                       
                    printf("\nPress 0 in row or col to quit() or giveup()");

                    int c=is_sudoku_full(puzzle);                             
                    if (c)
                        {//asking him to exit since sudoku is already oslved
                        printf("\nThe sudoku is full.Press 0 to quit\n\n");
                        }                                                                                                   
                    //printing the sudoku for user to see
                    printSudoku(puzzle);  
                    //asking him for the inputs                                                                                 
                    printf("\nPlease enter the Row:");
                    scanf("%d",&row);
                    printf("Please entr the column:");                                                                   
                    scanf("%d",&col);
                    //giving him a chance to quit()
                    if (row==0||col==0)                                                                                   
                        {cond_2=0;
                        system("clear");
                        printf("\nYour progress is saved\n");
                        rewind(sud);
                        fwrite(puzzle,sizeof(int),SIZE*SIZE,sud);
                        fclose(sud);
                        break;
                        }
                        else if(puzzle[row-1][col-1]==0)
                            {printf("\nPlease enter your answer");                                                            
                            scanf("%d",&answer);
                            //if user answering empty blocks
                            if (answer==process[row-1][col-1])
                                {puzzle[row-1][col-1]=answer;
                                printf("\n\nYour guess is correct");

                                //if user solved our sudoku congrats and his badges must also increase hence;
                                if (is_sudoku_full(puzzle))                                                                  
                                        {details=fopen("details","r+b");
                                        while(!feof(details))
                                        {user update;
                                            details=fopen("details","r+b");
                                            while(fread(&update,sizeof(user),1,details))
                                            { if (strcmp(person.name,update.name)==0)
                                                    {   
                                                        printf("Reached here");
                                                        update.number++;
                                                        fseek(details,-sizeof(user),1);
                                                        fwrite(&update,sizeof(user),1,details);
                                                        fclose(details);
                                                        printf("\nUpdated your badges on leaderboard");
                                                        break;
                                                    }
                                            }
                                        }
                                        printf("\n\nCongrats %s! You Cracked the sudoku\n\n",person.name);
                                        rewind(sud);
                                        fwrite(puzzle,sizeof(int),SIZE*SIZE,sud);
                                        fclose(sud);
                                        cond_2=0;
                                        }
                                }
                            else 
                            //if he entered a worng answer
                            printf("\nWrong Answer");
                            }
                            else
                            //Answer is already there.
                            printf("\nAnswer already there!!%d",process[row-1][col-1]);

                    }
                    break;



    case 3:
            //asking the computer to solve the existing sudoku
            sud=fopen(person.name,"r+b");                                                                                 
            if (!sud)
            {//if a fellow did not gen his sudoku.ask him to gen it.
                printf("\nPlease generate your fist sudoku to solve one.Press(1)\n");
                break;
            }
            //displaying the question
            printf("\n The puzzle you tried to solve was:\n");
            sud=fopen(person.name,"rb");
            rewind(sud);
            fread(&puzzle,sizeof(int),SIZE*SIZE,sud);
            printSudoku(puzzle);
            printf("\nThe solution of the above puzzle is:");

            solveSudoku(puzzle);

            //displaying the answer
            printSudoku(puzzle);
            printf("\nGenerate a new game and give it another shot");
            fclose(sud);
            sud=fopen(person.name,"wb");
            rewind(sud);
            fwrite(&puzzle,sizeof(int),SIZE*SIZE,sud);
            fclose(sud);
            break;
        


    case 4:
            //asking the user for any sudoku he wanted to solve an solving it for him
            int solve[SIZE][SIZE];
            int u;
            //taking the inputs
            input(solve);
                printf("\nThe following is the sudoku you entered:");
                printSudoku(solve); 
            
            //solving the sudoku
            u=solveSudoku(solve);
            if (u){
            printf("\nThe following is the solution of the sudoku");
            printSudoku(solve);
            }

            else
                //incase invalid sudoku
                printf("\nNo answer found for your sudoku");
            break;
            


    case 5:
            //sorting the badges as and when the usr asks
            details=fopen("details","r+b");
            sort_by_num(details);
            display_details(details);
            fclose(details);
            break;



    case 6:
            //cleaning up the dashboard
            system("clear");
            break;

    case 7:
            //exiting the game when the user adks
            check=0;
            break;
       
    default:
            break;
    };
    }
    return 0;
}