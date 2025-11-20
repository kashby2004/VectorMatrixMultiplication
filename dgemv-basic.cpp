const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply
   // Loop over rows of matrix A (i = row index)
   for (int i = 0; i < n; i++) {
      double accumulator = y[i];          // start from current y[i]
      const double* Ai = &A[i * n];       // pointer to row i of A (row-major)

      // Loop over columns of matrix A (j = column index)
      for (int j = 0; j < n; j++) {
         accumulator += Ai[j] * x[j];    // accumulate A[i][j] * x[j]
      }

      y[i] = accumulator;                 // store final result into y[i]
   }
}