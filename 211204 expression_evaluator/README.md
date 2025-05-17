Expression Evaluator

This is a simple expression evaluator program that takes an infix expression, converts it to postfix notation, and then evaluates the postfix expression to produce a result.
Project Structure

The project is structured as follows:

  expression_evaluator/
│
├── lexer.c          // Source file for lexical analysis (tokenization)
├── lexer.h          // Header file for lexer
│
├── parser.c         // Source file for parsing infix to postfix
├── parser.h         // Header file for parser
│
├── evaluator.c      // Source file for evaluating postfix expressions
├── evaluator.h      // Header file for evaluator
│
├── main.c           // Main file where user input is taken and modules are invoked
└── Makefile         // Makefile to compile the project


Building the Project

To build the project, you can use the provided Makefile. Simply navigate to the project directory in your terminal and run the following command:

bash

make

This will compile all the source files and generate an executable named expression_evaluator.
Running the Program

Once the project is built, you can run the program by executing the generated executable. The program expects an infix expression as a command-line argument. For example:

bash

./expression_evaluator "2 + 3 * (4 - 1)"

This will evaluate the infix expression "2 + 3 * (4 - 1)", convert it to postfix notation, and then compute the result.
Error Handling

The program includes error handling for invalid expressions, division by zero, mismatched parentheses, and other potential issues. Error messages will be displayed on the standard error stream (stderr) when such errors occur.

Dependencies

The project depends on the standard C libraries and does not require any external dependencies.

Author

This project was created by Ayushman Singh. You can contact me at ayushmansinghbais7@gmail.com for any questions or feedback regarding the project.
