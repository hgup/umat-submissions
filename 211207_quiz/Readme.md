This program is designed to conduct a quiz and store the results in a CSV file. It allows users to input their name and registration number, answer quiz questions, and view their scores. The program also maintains a leaderboard of quiz results.
This program requires a C compiler and standard C libraries. It also relies on the header file "header.h" for function prototypes and struct definitions.

To compile the program, use the following command:
make

To run the program, execute the following command:
./quiz

File Structure
- program.c: Contains the main program logic
- header.h: Header file with function prototypes and struct definitions
- C.csv: Input file containing quiz questions and answers
- results.csv: Output file storing quiz results and leaderboard data

Functionality:
- Users are prompted to enter their name and registration number before taking the quiz.
- The program reads quiz questions from the "C.csv" file and presents them to the user.
- There are 3 types of questions, namely, MCQs, True or False and One word answers. The answers aren't case sensitive.
- Users input their answers, and the program calculates their scores based on correct responses.
- Quiz results, including the user's name, registration number, and score, are appended to the "results.csv" file.
- The program also reads existing quiz results from "results.csv" to display a leaderboard sorted by scores.

Troubleshooting:
- If you encounter errors related to file handling, ensure that the input files ("C.csv" and "results.csv") are located in the same directory as the program executable.
- If the program enters an infinite loop or crashes unexpectedly, check for errors in the logic of input processing and file handling.

Contributions to this project are welcome! If you find any bugs or have suggestions for improvements, please open an issue on GitHub or submit a pull request.
