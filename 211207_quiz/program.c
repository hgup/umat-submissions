#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "header.h"
#define MAX_NAME_LENGTH 250
#define MAX_REGD_LENGTH 20
#define MAX_QUIZZES 100


int enterUserName(char *name) {


   int regd_no;
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
   
   
    // Remove newline character if present
    name[strcspn(name, "\n")] = '\0';
    printf("Enter your regd no.:");
    scanf("%d",&regd_no);
    return regd_no;
   
   
    // Remove newline character if present
   // name[strcspn(regd_no, "\n")] = '\0';
}



void sortLeaderboard(struct QuizResult leaderboard[], int numQuizzes) {
    for (int i = 0; i < numQuizzes - 1; i++) {
        for (int j = 0; j < numQuizzes - i - 1; j++) {
            if (leaderboard[j].score < leaderboard[j + 1].score) {
                // Swap the elements
                struct QuizResult temp = leaderboard[j];
                leaderboard[j] = leaderboard[j + 1];
                leaderboard[j + 1] = temp;
            }
        }
    }
    
    printf("\n\n\t\t\tLeaderboard\n\n\n");
      printf("Name\t\t\tRegd. No.\t\t\t\t Score\n");
        printf("------------------------------------------------------------------------------\n");
        
    for(int k=0;k<numQuizzes;k++)
    {
    printf("%-20s",leaderboard[k].name);
    printf("%-40d",leaderboard[k].regdNo);
    printf("%-45d",leaderboard[k].score);
    printf("\n");
    }
}

 
int input_run_quiz(char* filename)
{	
	FILE* fp=fopen("C.csv","r");


    if(!fp)
    {printf("Error opening the file");
    return 0;
    }
    
    else{
        
       char line[1024];
    
        char paragraph[10000];
        char buffer[1024];
 
        int row = 0;
        int column = 0;
        int score=0;
        char ans[10];
        int prev_value=0;
        
        while(fgets(buffer,1024,fp) && (!feof(fp)))
        {
            column=0;
            row++;
            if (row==1)
            continue;
            

            
            char* value=strtok(buffer,",");
            int val=atoi(value);
            
           
            if((prev_value==1)&&((val==2)||(val==3)))
                getchar();
            
            
            prev_value=val;
            
            if(val==1)
            {
                
            while((column<6)&&(value!=NULL))
            {
                if(column==1)
                {
                    printf("\n%d...",row-1);
                }
                
                
                if(column==2)
                {
                    
                    printf("a)");
                }
                
                      if(column==3)
                        printf("b)");
                
                      if(column==4)
                        printf("c)");
                        
                          
                      if(column==5)
                        printf("d)");
          
                if(column!=0)
                    printf("%s\n",value);
                
                            value=strtok(NULL,",");
                                      column++;
                
                
            }
                
             
            //printf("%s",value);
            
            printf("Enter your choice:");
            scanf("%s",ans);
           

		 if(strcasecmp(ans,value)==0)
		   {  score++;
		      //printf("correct");
		     }   
                
            printf("\n");
            
            
            }
        
            else if((val==2)||(val==3))
            {  
                if(val==2)
                    printf("\nTrue/False\n");
                
                
                
                else
                    printf("\nGive a one word answer:\n");
                
                
                while((value!=NULL)&&(column<2))
                {   if(column==1)
                    {
                    printf("%d...",row-1);
                    }   
                    
                    if(column==1)
                    printf("%s\n",value);
                                
                            value=strtok(NULL,",");
                                      column++;
                  
            
                }
                
                //printf("%s\n",value);
                gets(ans);
                //column+=2;
                //value=strtok(NULL,",");
                 
               
                 if(strcasecmp(ans,value)==0)
                { score++;
                  //printf("correct");
                }   
                
                
                
                
                
            }
        
        }
        
        printf("\n\nYour score is %d\n",score);
        fclose(fp);
        return score;
        
    
        }



}



void writeResultsToFile(struct QuizResult leaderboard[], int numQuizzes) {
    FILE *file = fopen("results.csv", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
        
     fprintf(file, "%s,%s,%s\n", "Name","Regd. No.", "Score");
    // Write sorted results to the file
    
    for (int i = 0; i < numQuizzes; i++) {
         //printf("%s,%d,%d\n", leaderboard[i].name, leaderboard[i].regdNo, leaderboard[i].score);
        fprintf(file, "%s,%d,%d\n", leaderboard[i].name, leaderboard[i].regdNo, leaderboard[i].score);
    }

    fclose(file);
}



/*int userAlreadyExists(const int regd_no) {
    FILE *file = fopen("results.csv", "r");
    if (file == NULL) {
        //printf("Error opening file.\n");
        return 1; // File does not exist or cannot be opened
    }

    char line[1024];
    char userName[MAX_NAME_LENGTH];
    int regdNo;
    
    while (fgets(line, sizeof(line), file)) {
        // Parse each line to extract name and regdNo
        sscanf(line, "%[^,],%d", userName, &regdNo);

        // Compare the parsed name and regdNo with the input
        if (regd_no == regdNo) {
            fclose(file);
            return 1; // User exists in the results.csv file
        }
    }

    fclose(file);
    return 0; // User does not exist in the results.csv file
}*/
