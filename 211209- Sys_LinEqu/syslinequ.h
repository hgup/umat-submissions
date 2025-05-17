void luFactorization(double **A, double **L, double **U, int n);
void forwardSubstitution(double **L, double *b, double *y, int n);
void backwardSubstitution(double **U, double *y, double *x, int n);
void printVector(double *vector, int n);
void printMat(double** mat, int n);