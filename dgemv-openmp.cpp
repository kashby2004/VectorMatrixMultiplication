#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

   /*#pragma omp parallel
   {
      int nthreads = omp_get_num_threads();
      int thread_id = omp_get_thread_num();
      printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
      printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
   }*/

   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings

   double accumulator;
   // Loop over rows of matrix A (i = row index)
   #pragma omp parallel for private(accumulator)
   for (int i = 0; i < n; i++) {
      accumulator = y[i];          // start from current y[i]
      const double* Ai = &A[i * n];       // pointer to row i of A (row-major)

      // Loop over columns of matrix A (j = column index)
      for (int j = 0; j < n; j++) {
         accumulator += Ai[j] * x[j];    // accumulate A[i][j] * x[j]
      }

      y[i] = accumulator;                 // store final result into y[i]
   }

}

