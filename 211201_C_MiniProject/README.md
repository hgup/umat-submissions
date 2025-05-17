Implementation of Backtracking in C

Demonstration on how to run this C program

    We use makefile to seamlessly execute our program
    
    Enter "make && ./backtrack" in the output terminal to execute the program and the follow the prompts on the terminal.

    A Demo:
    
    make && ./backtrack

    <compilation messages follow>

    Which Game Would You Like To Play?

    1. Knight's Tour
    
    2. N queens

    3. Quit

    <enter your choice here>

    <the game follows>

    <enter 3 when you want to quit the game>

    3 

    Your Choice is 3. Quit

    Bye Bye!

    <end of program run>


Knight's Tour

    The Knight's Tour Problem's objective is to find a path (if it exists) for the knight that covers every square of the chess board EXACTLY once.

    We make use of the following functions:

        1. mainKT() - asks the user for the starting position of the knight and then gives the same (if valid) to the other functions to solve the problem at hand based on the input. 

        2. print_board(int knightX, int knightY) - accepts the current location of the knight and prints the board accordingly and then also prints the same to a text file "knights.txt".

        3. valid(int x, int y) - accepts co-ordinates and checks if that position is valid or not. Returns 1 if valid, else 0.

        4. solve_board(int x, int y, int n) - the main function which solves the problem by recursively calling itself. 'n' is the no. of moves made so far.

        5. compar(const void *a, const void *b) comparison function used by qsort() to sort an array of valid moves based on their 'loneliness'. It compares two moves based on their 'loneliness' metrics and returns the result.

    
N_Queens 

    The N_Queens Problem's objective is to find a way to place N queens on a chessboard so that no two queens share the same row, column or diagonal.

    We make use of the following functions:
    
        1. printSolution(int board[N][N]) - accepts the current board set up and prints the final board setup after solving the problem and also prints the same to a file "n_queens.txt".

        2. isSafe(int board[N][N], int row, int col) - accepts the board set up and row and col and checks if a queen can be placed on the board on the given row and column.

        3. solveNQUtil(int board[N][N], int col) - accepts the board set up and column and returns either True or False based on whether a queen can be placed on a row in the column given.

        4. solveNQ() - like a driver program within our n_queens program which takes the user input for the starting position and then if the input is valid, the function moves forward the co-ordinates to the other functions to solve the problem based on the given input. 


bt_main

    bt_main is our main driver program. 
    It presents a choice to the user to choose which game he wishes to play and then accordingly implements that game by calling that corresponding function. 
