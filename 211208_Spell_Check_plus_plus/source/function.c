#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"

void correctit(char *word[0]){
    char temp;
    int i,j = 0;
    int k = 0;
    int counter = 0;

//Case 1: Swaping every two adjacent characters and ckecking for correctness.

    for (i = 0, j = 1; word[0][j] != '\0'; i++, j++) {
        temp = word[0][i];                                // Storing the first character temporarily
        word[0][i] = word[0][j];                          // Swapping the characters
        word[0][j] = temp;
        if (check(word[0])) {                             // Checking if the swapped word is correct
            k = printw(&word[0],k);      
        }
        temp = word[0][i];                                // Restoring the original order of characters
        word[0][i] = word[0][j];
        word[0][j] = temp;       
    }

// Case 2: Removing each character from its position and checking

        int l,m,n;       
        for(l=0; l < strlen(word[0]); l++){                // Selecting a char.
            char temp = word[0][l];                        // Copying the character that is going to be deleted
            
            for(m=l, n=m+1; n < strlen(word[0]); n++,m++){ // Deleting the char by shifting every char 
                word[0][m] = word[0][n];
                }
            word[0][m] = '\0';                             // Ending of char array
            if(check(word[0])){                            // Checking if the modified word is correct or not.
                k = printw(&word[0],k);    
                }  
            for( m--,n-- ;  m >= l ; n--,m--){             // taking all chars to their original positions
                word[0][n] = word[0][m];
                } 
            word[0][l] = temp;
                                                
            }   


//Case 3: Adding each character of all alphabets at all possible positions one at a time and checking for correctness

    word[1] = "abcdefghijklmnopqrstuvwxyz";
    int w,x,y,z; char t1,t2;

    // Iterate through each position in the word
    for(y = 0; y < strlen(word[0])+1 ; y++){
        // Shift characters to the right to make space for insertion
        for(x=y,t1 = 'a'; x < (strlen(word[0])+1); x++){
                t2 = word[0][x];
                word[0][x] = t1;
                t1 = t2;
                }
        
        // Check if the modified word is correct
        if(check(word[0])){
           k = printw(&word[0],k);
            }
        
        // Try inserting each alphabet at the current position
        for(z=1; z<26 ;z++){
                word[0][y] = word[1][z];

                // Check if the modified word is correct
                if(check(word[0])){
                    k = printw(&word[0],k);
                    }
            }
    
    // Remove the inserted character by shifting characters to the left
    for( w=y ; w < strlen(word[0])-1 ; w++){
        word[0][w] = word[0][w+1] ;
        }
        
        // End the string
        word[0][w] = '\0' ;
    }

// Case 4: Replace each character in the input word with each alphabet and check for correctness

    // Initialize variables
    int a, b, c;
    char t3;

    // Iterate through each character in the input word
    for(a = 0; a < strlen(word[0]) ; a++){
        // Save the current character
        t3 = word[0][a];

        // Iterate through the alphabet characters
        for(b = 0; b<26 ;b++){
            // Replace the current character with the alphabet character
            word[0][a] = word[1][b];

            // If the modified word is correct, print the word and increment the count
            if(check(word[0])){
                k = printw(word, k);
            }
        }
        
        // Revert the character back to its original state
        word[0][a] = t3;
    }
    if(!k)
        printf("\n\t The input word is too complex to correct.\n");
    // Print the original word before ending
    // printf("\nThe original word before ending is %s\n", word[0]);
}


// A function to print the word and increment the count
int printw(char *word[0], int k){
    if(!k){
        k++;
        printf("\nThe possible correct words are:");
        printf(" %d) %s\n", k, word[0]);
    } else {
        k++;
        printf("\t\t\t\t%d) %s\n", k, word[0]);
    }
    // Return the incremented count for the next iteration
    return k;
}
