/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_xaxpy(double a, double y[9], int iy0)
{
  if (!(a == 0.0)) {
    y[iy0 - 1] += a * y[1];
    y[iy0] += a * y[2];
  }
}

void c_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y)
{
  const double *x_data;
  double *y_data;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      y_data[k + 1] += a * x_data[(ix0 + k) - 1];
    }
  }
}

void d_xaxpy(int n, double a, const emxArray_real_T *x, emxArray_real_T *y,
             int iy0)
{
  const double *x_data;
  double *y_data;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int i;
      i = (iy0 + k) - 1;
      y_data[i] += a * x_data[k + 1];
    }
  }
}

void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
{
  double *y_data;
  int k;
  y_data = y->data;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int i;
      i = (iy0 + k) - 1;
      y_data[i] += a * y_data[(ix0 + k) - 1];
    }
  }
}

/* End of code generation (xaxpy.c) */
