/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * gradient.c
 *
 * Code generation for function 'gradient'
 *
 */

/* Include files */
#include "gradient.h"
#include "feature_extractor_codegen_emxutil.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void gradient(const emxArray_real_T *x, emxArray_real_T *varargout_1)
{
  const double *x_data;
  double *varargout_1_data;
  int i;
  int j;
  int loop_ub;
  x_data = x->data;
  loop_ub = x->size[0];
  i = varargout_1->size[0];
  varargout_1->size[0] = x->size[0];
  emxEnsureCapacity_real_T(varargout_1, i);
  varargout_1_data = varargout_1->data;
  if (x->size[0] >= 2) {
    varargout_1_data[0] = x_data[1] - x_data[0];
    for (j = 2; j < loop_ub; j++) {
      varargout_1_data[j - 1] = (x_data[j] - x_data[j - 2]) / 2.0;
    }
    varargout_1_data[x->size[0] - 1] =
        x_data[x->size[0] - 1] - x_data[x->size[0] - 2];
  } else {
    i = varargout_1->size[0];
    varargout_1->size[0] = x->size[0];
    emxEnsureCapacity_real_T(varargout_1, i);
    varargout_1_data = varargout_1->data;
    for (j = 0; j < loop_ub; j++) {
      varargout_1_data[0] = 0.0;
    }
  }
}

/* End of code generation (gradient.c) */
