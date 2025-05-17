#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "header.h"
#define MAX_NAME_LENGTH 250
#define MAX_REGD_LENGTH 20
#define MAX_QUIZZES 100






int main() {
    
    char userName[MAX_NAME_LENGTH];
    //char regd_no[20];
    int regd_no;
    

    regd_no=enterUserName(userName);
    
    struct QuizResult leaderboard[MAX_QUIZZES];
    int numQuizzes = 0;
     struct QuizResult userResult;
        
        //strcpy (userResult.regdNo,regd_no);
        userResult.regdNo=regd_no;
        strcpy(userResult.name,userName);

        userResult.score= input_run_quiz("C.csv");
    
  
        // Example: Reading results from a file
   
    
        // Append user's result to "results.csv" file
   FILE* file = fopen("results.csv", "a"); // Open file in append mode
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    
    

    fprintf(file, "%s,%d,%d\n", userResult.name, userResult.regdNo, userResult.score);
    fclose(file);  // Close the file after writing

    // Read all results from "results.csv" file
    file = fopen("results.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the header line
    char header[1024];
    fgets(header, sizeof(header), file);

    // Read results and store them in the leaderboard array
    while (fscanf(file, "%[^,],%d,%d\n", leaderboard[numQuizzes].name, &leaderboard[numQuizzes].regdNo, &leaderboard[numQuizzes].score) == 3) {
     
        numQuizzes++;
    }
    
    fclose(file);  // Close the file after reading

    // Sort the leaderboard in descending order based on scores
    sortLeaderboard(leaderboard, numQuizzes);

    // Write sorted results back to "results.csv" file
    writeResultsToFile(leaderboard, numQuizzes);

    printf("\nResults written to 'results.csv' successfully.\n");
  
    
    
    return 0;
}
    

