#include <stdio.h>
#include <stdlib.h>
#include "syslinequ.h"

int main() {
    int n; // Size of the matrix
    //there are n number of lines in the file

    printf("Enter the size of the matrix: ");  //n*n square matrix
    scanf("%d", &n);
    // Allocating memory for matrices
    double **A = (double **)malloc(n * sizeof(double *));
    double **L = (double **)malloc(n * sizeof(double *));
    double **U = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        L[i] = (double *)malloc(n * sizeof(double));
        U[i] = (double *)malloc(n * sizeof(double));
    }
    // Allocating memory for the resultant vector
    double *b = (double *)malloc(n * sizeof(double));
    

    // Taking input for coefficient matrix
    printf("Enter the coefficient matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }


    // Taking input for the resultant vector
    printf("Enter the resultant vector:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    luFactorization(A, L, U, n); // LU Factorization

    double *y = (double *)malloc(n * sizeof(double)); // For intermediate result
    forwardSubstitution(L, b, y, n);
    double *x = (double *)malloc(n * sizeof(double)); // Final result
    backwardSubstitution(U, y, x, n);

    // Printing the result
    printf("The solution vector is: ");
    printVector(x, n);

    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);
    free(b);
    free(y);
    free(x);

    return 0;
}