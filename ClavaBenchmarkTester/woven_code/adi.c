#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <polybench.h>
#include "adi.h"
/**
* This version is stamped on May 10, 2016
*
* Contact:
*   Louis-Noel Pouchet <pouchet.ohio-state.edu>
*   Tomofumi Yuki <tomofumi.yuki.fr>
*
* Web address: http://polybench.sourceforge.net
*/
/*adi.c: this file is part of PolyBench/C*/
/*Include polybench common header.*/
/*Include benchmark-specific header.*/
/*Array initialization.*/
static void init_array(int n, double u[60][60]) {
   int i, j;
   for(i = 0; i < n; i++)
      for(j = 0; j < n; j++) {
         u[i][j] = (double) (i + n - j) / n;
      }
}

/*DCE code. Must scan the entire live-out data.
Can be used also to check the correctness of the output.*/
static void print_array(int n, double u[60][60]) {
   int i, j;
   fprintf((__acrt_iob_func(2)), "==BEGIN DUMP_ARRAYS==\n");
   fprintf((__acrt_iob_func(2)), "begin dump: %s", "u");
   for(i = 0; i < n; i++)
      for(j = 0; j < n; j++) {
         if((i * n + j) % 20 == 0) fprintf((__acrt_iob_func(2)), "\n");
         fprintf((__acrt_iob_func(2)), "%0.2lf ", u[i][j]);
      }
   fprintf((__acrt_iob_func(2)), "\nend   dump: %s\n", "u");
   fprintf((__acrt_iob_func(2)), "==END   DUMP_ARRAYS==\n");
}

/*Main computational kernel. The whole function will be timed,
including the call and return.*/
/*Based on a Fortran code fragment from Figure 5 of
* "Automatic Data and Computation Decomposition on Distributed Memory Parallel Computers"
* by Peizong Lee and Zvi Meir Kedem, TOPLAS, 2002
*/
static void kernel_adi(int tsteps, int n, double u[60][60], double v[60][60], double p[60][60], double q[60][60]) {
   int t, i, j;
   double DX, DY, DT;
   double B1, B2;
   double mul1, mul2;
   double a, b, c, d, e, f;
   DX = 1.0 / (double) n;
   DY = 1.0 / (double) n;
   DT = 1.0 / (double) tsteps;
   B1 = 2.0;
   B2 = 1.0;
   mul1 = B1 * DT / (DX * DX);
   mul2 = B2 * DT / (DY * DY);
   a = -mul1 / 2.0;
   b = 1.0 + mul1;
   c = a;
   d = -mul2 / 2.0;
   e = 1.0 + mul2;
   f = d;
   for(t = 1; t <= tsteps; t++) {
      for(i = 1; i < n - 1; i++) {
         v[0][i] = 1.0;
         p[i][0] = 0.0;
         q[i][0] = v[0][i];
         for(j = 1; j < n - 1; j++) {
            p[i][j] = -c / (a * p[i][j - 1] + b);
            q[i][j] = (-d * u[j][i - 1] + (1.0 + 2.0 * d) * u[j][i] - f * u[j][i + 1] - a * q[i][j - 1]) / (a * p[i][j - 1] + b);
         }
         v[n - 1][i] = 1.0;
         for(j = n - 2; j >= 1; j--) {
            v[j][i] = p[i][j] * v[j + 1][i] + q[i][j];
         }
      }
      for(i = 1; i < n - 1; i++) {
         u[i][0] = 1.0;
         p[i][0] = 0.0;
         q[i][0] = u[i][0];
         for(j = 1; j < n - 1; j++) {
            p[i][j] = -f / (d * p[i][j - 1] + e);
            q[i][j] = (-a * v[i - 1][j] + (1.0 + 2.0 * a) * v[i][j] - c * v[i + 1][j] - d * q[i][j - 1]) / (d * p[i][j - 1] + e);
         }
         u[i][n - 1] = 1.0;
         for(j = n - 2; j >= 1; j--) {
            u[i][j] = p[i][j] * u[i][j + 1] + q[i][j];
         }
      }
   }
}

int main(int argc, char **argv) {
   /*Retrieve problem size.*/
   int n = 60;
   int tsteps = 40;
   /*Variable declaration/allocation.*/
   double (*u)[60][60];
   u = (double (*)[60][60]) polybench_alloc_data((60 + 0) * (60 + 0), sizeof(double));
   ;
   double (*v)[60][60];
   v = (double (*)[60][60]) polybench_alloc_data((60 + 0) * (60 + 0), sizeof(double));
   ;
   double (*p)[60][60];
   p = (double (*)[60][60]) polybench_alloc_data((60 + 0) * (60 + 0), sizeof(double));
   ;
   double (*q)[60][60];
   q = (double (*)[60][60]) polybench_alloc_data((60 + 0) * (60 + 0), sizeof(double));
   ;
   /*Initialize array(s).*/
   init_array(n, *u);
   /*Start timer.*/
   polybench_timer_start();
   ;
   /*Run kernel.*/
   kernel_adi(tsteps, n, *u, *v, *p, *q);
   /*Stop and print timer.*/
   polybench_timer_stop();
   ;
   polybench_timer_print();
   ;
   /*Prevent dead-code elimination. All live-out data must be printed
   by the function call in argument.*/
   if(argc > 42 && !strcmp(argv[0], "")) print_array(n, *u);
   /*Be clean.*/
   free((void *) u);
   ;
   free((void *) v);
   ;
   free((void *) p);
   ;
   free((void *) q);
   ;
   
   return 0;
}
