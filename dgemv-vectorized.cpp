const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // Loop over rows of matrix A (i = row index)
   for (int i = 0; i < n; i++) {
      double accumulator = y[i];       // start from current y[i]
      int base = i * n;                // base index for row i (row-major)

      // Loop over columns of matrix A (j = column index)
      for (int j = 0; j < n; j++) {
         accumulator += A[base + j] * x[j];   // accumulate A[i][j] * x[j]
      }

      y[i] = accumulator;              // store final result into y[i]
   }
}
