/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pca.c
 *
 * Code generation for function 'pca'
 *
 */

/* Include files */
#include "pca.h"
#include "feature_extractor_codegen_emxutil.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
int pca(const emxArray_real_T *x, double varargout_1_data[],
        int varargout_1_size[2], emxArray_real_T *varargout_2,
        double varargout_3_data[])
{
  emxArray_boolean_T *naninfo_isNaN;
  emxArray_int32_T *naninfo_nNaNsInRow;
  emxArray_real_T *b_x;
  emxArray_real_T *score;
  emxArray_real_T *xNoNaNs;
  emxArray_real_T *y;
  double b_coeff_data[9];
  double coeff_data[9];
  double latent_data[3];
  double mu[3];
  const double *x_data;
  double sgn;
  double wcol;
  double xcol;
  double *score_data;
  double *y_data;
  int coeff_size[2];
  int DOF;
  int i;
  int j;
  int loop_ub;
  int minDOFnsv;
  int naninfo_nNaNs;
  int ns1;
  int nsv;
  int p;
  int varargout_3_size;
  int *naninfo_nNaNsInRow_data;
  bool noNaNs;
  bool *naninfo_isNaN_data;
  x_data = x->data;
  emxInit_real_T(&b_x, 2);
  loop_ub = x->size[0];
  nsv = b_x->size[0] * b_x->size[1];
  b_x->size[0] = x->size[0];
  b_x->size[1] = 3;
  emxEnsureCapacity_real_T(b_x, nsv);
  y_data = b_x->data;
  p = x->size[0] * 3;
  for (j = 0; j < p; j++) {
    y_data[j] = x_data[j];
  }
  naninfo_nNaNs = 0;
  ns1 = 0;
  emxInit_int32_T(&naninfo_nNaNsInRow, 1);
  nsv = naninfo_nNaNsInRow->size[0];
  naninfo_nNaNsInRow->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(naninfo_nNaNsInRow, nsv);
  naninfo_nNaNsInRow_data = naninfo_nNaNsInRow->data;
  for (j = 0; j < loop_ub; j++) {
    naninfo_nNaNsInRow_data[j] = 0;
  }
  emxInit_boolean_T(&naninfo_isNaN, 2);
  nsv = naninfo_isNaN->size[0] * naninfo_isNaN->size[1];
  naninfo_isNaN->size[0] = x->size[0];
  naninfo_isNaN->size[1] = 3;
  emxEnsureCapacity_boolean_T(naninfo_isNaN, nsv);
  naninfo_isNaN_data = naninfo_isNaN->data;
  for (j = 0; j < p; j++) {
    naninfo_isNaN_data[j] = rtIsNaN(x_data[j]);
  }
  for (j = 0; j < 3; j++) {
    for (i = 0; i < loop_ub; i++) {
      if (naninfo_isNaN_data[i + naninfo_isNaN->size[0] * j]) {
        naninfo_nNaNsInRow_data[i]++;
        naninfo_nNaNs++;
      }
    }
  }
  emxFree_boolean_T(&naninfo_isNaN);
  for (j = 0; j < loop_ub; j++) {
    if (naninfo_nNaNsInRow_data[j] > 0) {
      ns1++;
    }
  }
  noNaNs = (naninfo_nNaNs <= 0);
  naninfo_nNaNs = x->size[0] - ns1;
  DOF = naninfo_nNaNs;
  if (naninfo_nNaNs >= 1) {
    DOF = naninfo_nNaNs - 1;
  }
  if (!noNaNs) {
    for (j = 0; j < 3; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (i = 0; i < loop_ub; i++) {
        sgn = x_data[i + x->size[0] * j];
        if (!rtIsNaN(sgn)) {
          wcol++;
          xcol += sgn;
        }
      }
      mu[j] = xcol / wcol;
    }
  } else {
    for (j = 0; j < 3; j++) {
      wcol = 0.0;
      xcol = 0.0;
      for (i = 0; i < loop_ub; i++) {
        wcol++;
        xcol += x_data[i + x->size[0] * j];
      }
      mu[j] = xcol / wcol;
    }
  }
  for (j = 0; j < 3; j++) {
    for (i = 0; i < loop_ub; i++) {
      y_data[i + b_x->size[0] * j] -= mu[j];
    }
  }
  emxInit_real_T(&y, 2);
  emxInit_real_T(&score, 2);
  if (noNaNs) {
    varargout_3_size = xzsvdc(b_x, y, latent_data, coeff_data, coeff_size);
    y_data = y->data;
    nsv = y->size[1];
    for (j = 0; j < nsv; j++) {
      for (i = 0; i < loop_ub; i++) {
        y_data[i + y->size[0] * j] *= latent_data[j];
      }
    }
    for (j = 0; j < nsv; j++) {
      wcol = latent_data[j];
      wcol = wcol * wcol / (double)DOF;
      latent_data[j] = wcol;
    }
    if (DOF < 3) {
      minDOFnsv = y->size[1];
      if (DOF <= minDOFnsv) {
        minDOFnsv = DOF;
      }
      nsv = score->size[0] * score->size[1];
      score->size[0] = x->size[0];
      score->size[1] = minDOFnsv;
      emxEnsureCapacity_real_T(score, nsv);
      score_data = score->data;
      for (j = 0; j < minDOFnsv; j++) {
        for (i = 0; i < loop_ub; i++) {
          score_data[i + score->size[0] * j] = y_data[i + y->size[0] * j];
        }
      }
      varargout_3_size = minDOFnsv;
      for (j = 0; j < minDOFnsv; j++) {
        varargout_3_data[j] = latent_data[j];
        b_coeff_data[3 * j] = coeff_data[3 * j];
        nsv = 3 * j + 1;
        b_coeff_data[nsv] = coeff_data[nsv];
        nsv = 3 * j + 2;
        b_coeff_data[nsv] = coeff_data[nsv];
      }
    } else {
      nsv = score->size[0] * score->size[1];
      score->size[0] = y->size[0];
      score->size[1] = y->size[1];
      emxEnsureCapacity_real_T(score, nsv);
      score_data = score->data;
      nsv = y->size[0] * y->size[1];
      for (j = 0; j < nsv; j++) {
        score_data[j] = y_data[j];
      }
      if (varargout_3_size - 1 >= 0) {
        memcpy(&varargout_3_data[0], &latent_data[0],
               (unsigned int)varargout_3_size * sizeof(double));
      }
      minDOFnsv = coeff_size[1];
      nsv = 3 * coeff_size[1];
      if (nsv - 1 >= 0) {
        memcpy(&b_coeff_data[0], &coeff_data[0],
               (unsigned int)nsv * sizeof(double));
      }
    }
  } else {
    emxInit_real_T(&xNoNaNs, 2);
    nsv = xNoNaNs->size[0] * xNoNaNs->size[1];
    xNoNaNs->size[0] = naninfo_nNaNs;
    xNoNaNs->size[1] = 3;
    emxEnsureCapacity_real_T(xNoNaNs, nsv);
    score_data = xNoNaNs->data;
    nsv = -1;
    for (j = 0; j < loop_ub; j++) {
      if (naninfo_nNaNsInRow_data[j] == 0) {
        nsv++;
        score_data[nsv] = y_data[j];
        score_data[nsv + xNoNaNs->size[0]] = y_data[j + b_x->size[0]];
        score_data[nsv + xNoNaNs->size[0] * 2] = y_data[j + b_x->size[0] * 2];
      }
    }
    varargout_3_size =
        xzsvdc(xNoNaNs, score, latent_data, coeff_data, coeff_size);
    score_data = score->data;
    emxFree_real_T(&xNoNaNs);
    nsv = score->size[1];
    for (j = 0; j < nsv; j++) {
      for (i = 0; i < naninfo_nNaNs; i++) {
        score_data[i + score->size[0] * j] *= latent_data[j];
      }
    }
    for (j = 0; j < nsv; j++) {
      wcol = latent_data[j];
      wcol = wcol * wcol / (double)DOF;
      latent_data[j] = wcol;
    }
    if (DOF < 3) {
      minDOFnsv = score->size[1];
      if (DOF <= minDOFnsv) {
        minDOFnsv = DOF;
      }
      nsv = y->size[0] * y->size[1];
      y->size[0] = naninfo_nNaNs;
      y->size[1] = minDOFnsv;
      emxEnsureCapacity_real_T(y, nsv);
      y_data = y->data;
      for (j = 0; j < minDOFnsv; j++) {
        for (i = 0; i < naninfo_nNaNs; i++) {
          y_data[i + y->size[0] * j] = score_data[i + score->size[0] * j];
        }
      }
      varargout_3_size = minDOFnsv;
      for (j = 0; j < minDOFnsv; j++) {
        varargout_3_data[j] = latent_data[j];
        b_coeff_data[3 * j] = coeff_data[3 * j];
        nsv = 3 * j + 1;
        b_coeff_data[nsv] = coeff_data[nsv];
        nsv = 3 * j + 2;
        b_coeff_data[nsv] = coeff_data[nsv];
      }
    } else {
      nsv = y->size[0] * y->size[1];
      y->size[0] = score->size[0];
      y->size[1] = score->size[1];
      emxEnsureCapacity_real_T(y, nsv);
      y_data = y->data;
      nsv = score->size[0] * score->size[1];
      for (j = 0; j < nsv; j++) {
        y_data[j] = score_data[j];
      }
      if (varargout_3_size - 1 >= 0) {
        memcpy(&varargout_3_data[0], &latent_data[0],
               (unsigned int)varargout_3_size * sizeof(double));
      }
      minDOFnsv = coeff_size[1];
      nsv = 3 * coeff_size[1];
      if (nsv - 1 >= 0) {
        memcpy(&b_coeff_data[0], &coeff_data[0],
               (unsigned int)nsv * sizeof(double));
      }
    }
    p = y->size[1];
    nsv = score->size[0] * score->size[1];
    score->size[0] = x->size[0];
    score->size[1] = y->size[1];
    emxEnsureCapacity_real_T(score, nsv);
    score_data = score->data;
    nsv = -1;
    for (i = 0; i < loop_ub; i++) {
      if (naninfo_nNaNsInRow_data[i] > 0) {
        for (j = 0; j < p; j++) {
          score_data[i + score->size[0] * j] = rtNaN;
        }
      } else {
        nsv++;
        for (j = 0; j < p; j++) {
          score_data[i + score->size[0] * j] = y_data[nsv + y->size[0] * j];
        }
      }
    }
  }
  emxFree_real_T(&y);
  emxFree_int32_T(&naninfo_nNaNsInRow);
  emxFree_real_T(&b_x);
  ns1 = score->size[0];
  if (DOF > 3) {
    varargout_1_size[0] = 3;
    varargout_1_size[1] = 3;
    for (j = 0; j < 3; j++) {
      varargout_1_data[3 * j] = b_coeff_data[3 * j];
      nsv = 3 * j + 1;
      varargout_1_data[nsv] = b_coeff_data[nsv];
      nsv = 3 * j + 2;
      varargout_1_data[nsv] = b_coeff_data[nsv];
    }
    nsv = varargout_2->size[0] * varargout_2->size[1];
    varargout_2->size[0] = score->size[0];
    varargout_2->size[1] = 3;
    emxEnsureCapacity_real_T(varargout_2, nsv);
    y_data = varargout_2->data;
    for (j = 0; j < 3; j++) {
      for (i = 0; i < ns1; i++) {
        y_data[i + varargout_2->size[0] * j] =
            score_data[i + score->size[0] * j];
      }
    }
  } else {
    varargout_1_size[0] = 3;
    varargout_1_size[1] = minDOFnsv;
    nsv = 3 * minDOFnsv;
    if (nsv - 1 >= 0) {
      memcpy(&varargout_1_data[0], &b_coeff_data[0],
             (unsigned int)nsv * sizeof(double));
    }
    nsv = varargout_2->size[0] * varargout_2->size[1];
    varargout_2->size[0] = score->size[0];
    varargout_2->size[1] = score->size[1];
    emxEnsureCapacity_real_T(varargout_2, nsv);
    y_data = varargout_2->data;
    nsv = score->size[0] * score->size[1];
    for (j = 0; j < nsv; j++) {
      y_data[j] = score_data[j];
    }
  }
  emxFree_real_T(&score);
  naninfo_nNaNs = varargout_1_size[1];
  for (i = 0; i < naninfo_nNaNs; i++) {
    double d;
    double d1;
    xcol = 0.0;
    sgn = 1.0;
    d = varargout_1_data[3 * i];
    wcol = fabs(d);
    if (wcol > 0.0) {
      xcol = wcol;
      sgn = d;
      if (!rtIsNaN(d)) {
        if (d < 0.0) {
          sgn = -1.0;
        } else {
          sgn = (d > 0.0);
        }
      }
    }
    nsv = 3 * i + 1;
    d1 = varargout_1_data[nsv];
    wcol = fabs(d1);
    if (wcol > xcol) {
      xcol = wcol;
      sgn = d1;
      if (!rtIsNaN(d1)) {
        if (d1 < 0.0) {
          sgn = -1.0;
        } else {
          sgn = (d1 > 0.0);
        }
      }
    }
    p = 3 * i + 2;
    wcol = varargout_1_data[p];
    if (fabs(wcol) > xcol) {
      sgn = wcol;
      if (!rtIsNaN(wcol)) {
        if (wcol < 0.0) {
          sgn = -1.0;
        } else {
          sgn = (wcol > 0.0);
        }
      }
    }
    if (sgn < 0.0) {
      d = -d;
      varargout_1_data[3 * i] = d;
      d1 = -d1;
      varargout_1_data[nsv] = d1;
      wcol = -wcol;
      varargout_1_data[p] = wcol;
      for (j = 0; j < ns1; j++) {
        y_data[j + varargout_2->size[0] * i] =
            -y_data[j + varargout_2->size[0] * i];
      }
    }
  }
  return varargout_3_size;
}

/* End of code generation (pca.c) */
