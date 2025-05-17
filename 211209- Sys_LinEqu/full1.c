#include <stdio.h>
#include <stdlib.h>


void luFactorization(double **A, double **L, double **U, int n) {
    for (int i = 0; i < n; i++) {
        // Upper Triangular Matrix
        for (int k = i; k < n; k++) {    //columns
            double sum = 0.0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }
        // Lower Triangular Matrix
        for (int k = i; k < n; k++) {    //rows
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0.0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }

        }
    }
}

void forwardSubstitution(double **L, double *b, double *y, int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }
}

void backwardSubstitution(double **U, double *y, double *x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++)
            sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }
}

void printVector(double *vector, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.2f", vector[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int n; // Size of the matrix
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

    // Taking input for coefficient matrix
    printf("Enter the coefficient matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Allocating memory for the resultant vector
    double *b = (double *)malloc(n * sizeof(double));

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
