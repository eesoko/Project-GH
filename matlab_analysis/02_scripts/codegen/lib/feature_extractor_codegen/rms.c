/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rms.c
 *
 * Code generation for function 'rms'
 *
 */

/* Include files */
#include "rms.h"
#include "blockedSummation.h"
#include "feature_extractor_codegen_emxutil.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double rms(const emxArray_real_T *xIn)
{
  emxArray_real_T *x;
  const double *xIn_data;
  double y;
  double *x_data;
  int i;
  int i1;
  int loop_ub;
  xIn_data = xIn->data;
  emxInit_real_T(&x, 1);
  loop_ub = xIn->size[0];
  i = x->size[0];
  x->size[0] = xIn->size[0];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    x_data[i1] = xIn_data[i1] * xIn_data[i1];
  }
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = colMajorFlatIter(x, x->size[0]);
  }
  y = sqrt(y / (double)x->size[0]);
  emxFree_real_T(&x);
  return y;
}

/* End of code generation (rms.c) */
