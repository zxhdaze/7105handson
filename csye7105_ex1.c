/* CSYE7105 HW1 Q1: totals 14 points */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid, procs, maxt, inpar, dynamic, nested;

/* Start parallel region */
#pragma omp parallel private(nthreads, tid)
  {

  /* Please write the runtime routine to obtain thread number 
     2 points   */
  tid = omp_get_thread_num();

  /* Only master thread does this */
  if (tid == 0) 
    {
    printf("Thread %d getting environment info...\n", tid);

    /* Get environment information */
	/* the class slide or https://www.openmp.org/spec-html/5.0/openmpch3.html */
	/* 2 points for each routine; 12 points total*/

        procs = omp_get_num_procs();             // get the number of processors available to the device
        nthreads = omp_get_num_threads();        // get the number of threads
        maxt = omp_get_max_threads();            // get maximum threads available
        inpar = omp_in_parallel();               // is it in parallel?
        dynamic = omp_get_dynamic();             // Dynamic threads enabled?
        nested = omp_get_nested();               // Nested parallelism supported?


    /* Print environment information */
    printf("Number of processors = %d\n", procs);
    printf("Number of threads = %d\n", nthreads);
    printf("Max threads = %d\n", maxt);
    printf("In parallel? = %d\n", inpar);
    printf("Dynamic threads enabled? = %d\n", dynamic);
    printf("Nested parallelism supported? = %d\n", nested);

    }

  }  /* Done */

}
