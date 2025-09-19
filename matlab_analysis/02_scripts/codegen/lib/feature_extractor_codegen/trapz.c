/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trapz.c
 *
 * Code generation for function 'trapz'
 *
 */

/* Include files */
#include "trapz.h"
#include "feature_extractor_codegen_emxutil.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double trapz(const emxArray_real_T *x, const emxArray_real_T *y)
{
  emxArray_real_T *c;
  const double *x_data;
  const double *y_data;
  double z;
  double *c_data;
  int ia;
  int iac;
  y_data = y->data;
  x_data = x->data;
  z = 0.0;
  if (y->size[0] <= 1) {
    if ((x->size[0] == 1) && (rtIsInf(x_data[0]) || rtIsNaN(x_data[0]))) {
      z = rtNaN;
    }
  } else {
    double c1;
    int vlen;
    emxInit_real_T(&c, 1);
    if (x->size[0] == 1) {
      int loop_ub;
      loop_ub = y->size[0];
      vlen = c->size[0];
      c->size[0] = y->size[0];
      emxEnsureCapacity_real_T(c, vlen);
      c_data = c->data;
      for (iac = 0; iac < loop_ub; iac++) {
        c_data[iac] = x_data[0];
      }
      c1 = 0.5 * x_data[0];
      c_data[0] = c1;
      c_data[y->size[0] - 1] = c1;
    } else {
      int loop_ub;
      loop_ub = y->size[0];
      vlen = c->size[0];
      c->size[0] = y->size[0];
      emxEnsureCapacity_real_T(c, vlen);
      c_data = c->data;
      c_data[0] = 0.5 * (x_data[1] - x_data[0]);
      for (iac = 2; iac < loop_ub; iac++) {
        c_data[iac - 1] = 0.5 * (x_data[iac] - x_data[iac - 2]);
      }
      c_data[y->size[0] - 1] =
          0.5 * (x_data[y->size[0] - 1] - x_data[y->size[0] - 2]);
    }
    vlen = y->size[0];
    for (iac = 1; vlen < 0 ? iac >= 1 : iac <= 1; iac += vlen) {
      c1 = 0.0;
      for (ia = 1; ia <= vlen; ia++) {
        c1 += y_data[ia - 1] * c_data[ia - 1];
      }
      z += c1;
    }
    emxFree_real_T(&c);
  }
  return z;
}

/* End of code generation (trapz.c) */
