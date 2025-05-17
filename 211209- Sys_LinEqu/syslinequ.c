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

void printMat(double** mat, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}