/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * periodogram.c
 *
 * Code generation for function 'periodogram'
 *
 */

/* Include files */
#include "periodogram.h"
#include "FFTImplementationCallback.h"
#include "feature_extractor_codegen_emxutil.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void periodogram(const emxArray_real_T *x, double varargin_3,
                 emxArray_real_T *Px, emxArray_real_T *w)
{
  emxArray_creal_T *Xx;
  emxArray_real_T *b_select;
  emxArray_real_T *b_xw;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  emxArray_real_T *wrappedData;
  emxArray_real_T *xw;
  creal_T *Xx_data;
  const double *x_data;
  double Fs;
  double Nyq;
  double b_halfNPTS_tmp;
  double f;
  double freq_res;
  double halfNPTS_tmp;
  double half_res;
  double isNPTSodd_tmp;
  double obj_next_next_value;
  double *Px_data;
  double *b_xw_data;
  double *costab1q_data;
  double *select_data;
  double *wrappedData_data;
  double *xw_data;
  int acoef;
  int b_k;
  int b_n2;
  int csz_idx_0;
  int k;
  int n2;
  int nFullPasses;
  bool Fs_tmp;
  bool useRadix2;
  x_data = x->data;
  f = frexp(x->size[0], &acoef);
  if (f == 0.5) {
    acoef--;
  }
  if (acoef == 0) {
    f = 1.0;
  } else if (acoef == 1) {
    f = 2.0;
  } else if (acoef == 2) {
    f = 4.0;
  } else {
    f = pow(2.0, acoef);
  }
  obj_next_next_value = fmax(256.0, f);
  Fs_tmp = rtIsNaN(varargin_3);
  if (Fs_tmp) {
    Fs = 6.2831853071795862;
  } else {
    Fs = varargin_3;
  }
  if (x->size[0] == 1) {
    csz_idx_0 = x->size[0];
  } else if (x->size[0] == 1) {
    csz_idx_0 = 1;
  } else {
    csz_idx_0 = x->size[0];
  }
  emxInit_real_T(&xw, 1);
  acoef = xw->size[0];
  xw->size[0] = csz_idx_0;
  emxEnsureCapacity_real_T(xw, acoef);
  xw_data = xw->data;
  if (csz_idx_0 != 0) {
    acoef = (x->size[0] != 1);
    for (k = 0; k < csz_idx_0; k++) {
      xw_data[k] = x_data[acoef * k];
    }
  }
  emxInit_real_T(&b_xw, 1);
  if (xw->size[0] > obj_next_next_value) {
    n2 = (int)obj_next_next_value;
    acoef = b_xw->size[0];
    b_xw->size[0] = (int)obj_next_next_value;
    emxEnsureCapacity_real_T(b_xw, acoef);
    b_xw_data = b_xw->data;
    for (k = 0; k < n2; k++) {
      b_xw_data[k] = 0.0;
    }
    emxInit_real_T(&wrappedData, 2);
    acoef = wrappedData->size[0] * wrappedData->size[1];
    wrappedData->size[0] = (int)obj_next_next_value;
    wrappedData->size[1] = 1;
    emxEnsureCapacity_real_T(wrappedData, acoef);
    wrappedData_data = wrappedData->data;
    for (k = 0; k < n2; k++) {
      wrappedData_data[k] = 0.0;
    }
    nFullPasses =
        (int)((unsigned int)xw->size[0] / (unsigned int)obj_next_next_value);
    acoef = nFullPasses * (int)obj_next_next_value;
    csz_idx_0 = (xw->size[0] - acoef) - 1;
    for (k = 0; k <= csz_idx_0; k++) {
      wrappedData_data[k] = xw_data[acoef + k];
    }
    acoef = csz_idx_0 + 2;
    for (k = acoef; k <= n2; k++) {
      wrappedData_data[k - 1] = 0.0;
    }
    for (k = 0; k < nFullPasses; k++) {
      acoef = k * (int)obj_next_next_value;
      for (b_k = 0; b_k < n2; b_k++) {
        wrappedData_data[b_k] += xw_data[acoef + b_k];
      }
    }
    for (k = 0; k < n2; k++) {
      b_xw_data[k] = wrappedData_data[k];
    }
    emxFree_real_T(&wrappedData);
  } else {
    acoef = b_xw->size[0];
    b_xw->size[0] = csz_idx_0;
    emxEnsureCapacity_real_T(b_xw, acoef);
    b_xw_data = b_xw->data;
    for (k = 0; k < csz_idx_0; k++) {
      b_xw_data[k] = xw_data[k];
    }
  }
  emxInit_real_T(&b_select, 2);
  emxInit_creal_T(&Xx);
  emxInit_real_T(&costab1q, 2);
  if (b_xw->size[0] == 0) {
    csz_idx_0 = (int)obj_next_next_value;
    acoef = Xx->size[0];
    Xx->size[0] = (int)obj_next_next_value;
    emxEnsureCapacity_creal_T(Xx, acoef);
    Xx_data = Xx->data;
    for (k = 0; k < csz_idx_0; k++) {
      Xx_data[k].re = 0.0;
      Xx_data[k].im = 0.0;
    }
  } else {
    useRadix2 =
        (((int)obj_next_next_value & ((int)obj_next_next_value - 1)) == 0);
    n2 = 1;
    if (useRadix2) {
      acoef = (int)obj_next_next_value;
    } else {
      bool exitg1;
      acoef = ((int)obj_next_next_value + (int)obj_next_next_value) - 1;
      b_n2 = 31;
      csz_idx_0 = 0;
      exitg1 = false;
      while ((!exitg1) && (b_n2 - csz_idx_0 > 1)) {
        nFullPasses = (csz_idx_0 + b_n2) >> 1;
        n2 = 1 << nFullPasses;
        if (n2 == acoef) {
          b_n2 = nFullPasses;
          exitg1 = true;
        } else if (n2 > acoef) {
          b_n2 = nFullPasses;
        } else {
          csz_idx_0 = nFullPasses;
        }
      }
      n2 = 1 << b_n2;
      acoef = n2;
    }
    f = 6.2831853071795862 / (double)acoef;
    b_n2 = (int)(((unsigned int)acoef >> 1) >> 1);
    acoef = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = b_n2 + 1;
    emxEnsureCapacity_real_T(costab1q, acoef);
    costab1q_data = costab1q->data;
    costab1q_data[0] = 1.0;
    acoef = (int)((unsigned int)b_n2 >> 1) - 1;
    for (k = 0; k <= acoef; k++) {
      costab1q_data[k + 1] = cos(f * ((double)k + 1.0));
    }
    acoef += 2;
    for (k = acoef; k < b_n2; k++) {
      costab1q_data[k] = sin(f * (double)(b_n2 - k));
    }
    costab1q_data[b_n2] = 0.0;
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    if (!useRadix2) {
      csz_idx_0 = costab1q->size[1] - 1;
      b_n2 = (costab1q->size[1] - 1) << 1;
      acoef = b_select->size[0] * b_select->size[1];
      b_select->size[0] = 1;
      b_select->size[1] = b_n2 + 1;
      emxEnsureCapacity_real_T(b_select, acoef);
      select_data = b_select->data;
      acoef = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = b_n2 + 1;
      emxEnsureCapacity_real_T(sintab, acoef);
      wrappedData_data = sintab->data;
      select_data[0] = 1.0;
      wrappedData_data[0] = 0.0;
      acoef = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = b_n2 + 1;
      emxEnsureCapacity_real_T(sintabinv, acoef);
      xw_data = sintabinv->data;
      for (k = 0; k < csz_idx_0; k++) {
        xw_data[k + 1] = costab1q_data[(csz_idx_0 - k) - 1];
      }
      acoef = costab1q->size[1];
      for (k = acoef; k <= b_n2; k++) {
        xw_data[k] = costab1q_data[k - csz_idx_0];
      }
      for (k = 0; k < csz_idx_0; k++) {
        select_data[k + 1] = costab1q_data[k + 1];
        wrappedData_data[k + 1] = -costab1q_data[(csz_idx_0 - k) - 1];
      }
      for (k = acoef; k <= b_n2; k++) {
        select_data[k] = -costab1q_data[b_n2 - k];
        wrappedData_data[k] = -costab1q_data[k - csz_idx_0];
      }
      c_FFTImplementationCallback_dob(b_xw, n2, (int)obj_next_next_value,
                                      b_select, sintab, sintabinv, Xx);
      Xx_data = Xx->data;
    } else {
      b_n2 = costab1q->size[1] - 1;
      n2 = (costab1q->size[1] - 1) << 1;
      acoef = b_select->size[0] * b_select->size[1];
      b_select->size[0] = 1;
      b_select->size[1] = n2 + 1;
      emxEnsureCapacity_real_T(b_select, acoef);
      select_data = b_select->data;
      acoef = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = n2 + 1;
      emxEnsureCapacity_real_T(sintab, acoef);
      wrappedData_data = sintab->data;
      select_data[0] = 1.0;
      wrappedData_data[0] = 0.0;
      for (k = 0; k < b_n2; k++) {
        select_data[k + 1] = costab1q_data[k + 1];
        wrappedData_data[k + 1] = -costab1q_data[(b_n2 - k) - 1];
      }
      acoef = costab1q->size[1];
      for (k = acoef; k <= n2; k++) {
        select_data[k] = -costab1q_data[n2 - k];
        wrappedData_data[k] = -costab1q_data[k - b_n2];
      }
      csz_idx_0 = (int)obj_next_next_value;
      acoef = Xx->size[0];
      Xx->size[0] = (int)obj_next_next_value;
      emxEnsureCapacity_creal_T(Xx, acoef);
      if ((int)obj_next_next_value > b_xw->size[0]) {
        acoef = Xx->size[0];
        Xx->size[0] = (int)obj_next_next_value;
        emxEnsureCapacity_creal_T(Xx, acoef);
        Xx_data = Xx->data;
        for (k = 0; k < csz_idx_0; k++) {
          Xx_data[k].re = 0.0;
          Xx_data[k].im = 0.0;
        }
      }
      c_FFTImplementationCallback_doH(b_xw, Xx, (int)obj_next_next_value,
                                      b_select, sintab);
      Xx_data = Xx->data;
    }
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
  }
  freq_res = Fs / obj_next_next_value;
  acoef = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = (int)(obj_next_next_value - 1.0) + 1;
  emxEnsureCapacity_real_T(costab1q, acoef);
  costab1q_data = costab1q->data;
  acoef = (int)(obj_next_next_value - 1.0);
  for (k = 0; k <= acoef; k++) {
    costab1q_data[k] = k;
  }
  acoef = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  emxEnsureCapacity_real_T(costab1q, acoef);
  costab1q_data = costab1q->data;
  acoef = costab1q->size[1] - 1;
  for (k = 0; k <= acoef; k++) {
    costab1q_data[k] *= freq_res;
  }
  Nyq = Fs / 2.0;
  half_res = freq_res / 2.0;
  isNPTSodd_tmp = fmod(obj_next_next_value, 2.0);
  if (rtIsInf(obj_next_next_value)) {
    f = rtNaN;
  } else {
    f = isNPTSodd_tmp;
  }
  useRadix2 = (f != 0.0);
  halfNPTS_tmp = obj_next_next_value / 2.0 + 1.0;
  b_halfNPTS_tmp = (obj_next_next_value + 1.0) / 2.0;
  if (useRadix2) {
    costab1q_data[(int)b_halfNPTS_tmp - 1] = Nyq - half_res;
    costab1q_data[(int)(unsigned int)b_halfNPTS_tmp] = Nyq + half_res;
  } else {
    costab1q_data[(int)halfNPTS_tmp - 1] = Nyq;
  }
  costab1q_data[(int)obj_next_next_value - 1] = Fs - freq_res;
  csz_idx_0 = x->size[0];
  b_n2 = Xx->size[0];
  acoef = xw->size[0];
  xw->size[0] = Xx->size[0];
  emxEnsureCapacity_real_T(xw, acoef);
  xw_data = xw->data;
  for (k = 0; k < b_n2; k++) {
    f = Xx_data[k].re;
    freq_res = Xx_data[k].im;
    Nyq = f * f - freq_res * -freq_res;
    if (f * -freq_res + freq_res * f == 0.0) {
      f = Nyq / (double)csz_idx_0;
    } else if (Nyq == 0.0) {
      f = 0.0;
    } else {
      f = Nyq / (double)csz_idx_0;
    }
    xw_data[k] = f;
  }
  emxFree_creal_T(&Xx);
  if ((int)isNPTSodd_tmp == 1) {
    acoef = b_select->size[0] * b_select->size[1];
    b_select->size[0] = 1;
    b_select->size[1] = (int)(b_halfNPTS_tmp - 1.0) + 1;
    emxEnsureCapacity_real_T(b_select, acoef);
    select_data = b_select->data;
    b_n2 = (int)(b_halfNPTS_tmp - 1.0);
    for (k = 0; k <= b_n2; k++) {
      select_data[k] = (double)k + 1.0;
    }
    acoef = Px->size[0];
    Px->size[0] = (int)(b_halfNPTS_tmp - 1.0) + 1;
    emxEnsureCapacity_real_T(Px, acoef);
    Px_data = Px->data;
    for (k = 0; k <= b_n2; k++) {
      Px_data[k] = xw_data[k];
    }
    acoef = b_xw->size[0];
    b_xw->size[0] = (int)(b_halfNPTS_tmp - 1.0);
    emxEnsureCapacity_real_T(b_xw, acoef);
    b_xw_data = b_xw->data;
    for (k = 0; k < b_n2; k++) {
      b_xw_data[k] = 2.0 * Px_data[k + 1];
    }
    for (k = 0; k < b_n2; k++) {
      Px_data[k + 1] = b_xw_data[k];
    }
  } else {
    acoef = b_select->size[0] * b_select->size[1];
    b_select->size[0] = 1;
    b_select->size[1] = (int)(halfNPTS_tmp - 1.0) + 1;
    emxEnsureCapacity_real_T(b_select, acoef);
    select_data = b_select->data;
    nFullPasses = (int)(halfNPTS_tmp - 1.0);
    for (k = 0; k <= nFullPasses; k++) {
      select_data[k] = (double)k + 1.0;
    }
    acoef = Px->size[0];
    Px->size[0] = (int)(halfNPTS_tmp - 1.0) + 1;
    emxEnsureCapacity_real_T(Px, acoef);
    Px_data = Px->data;
    for (k = 0; k <= nFullPasses; k++) {
      Px_data[k] = xw_data[k];
    }
    b_n2 = (int)(halfNPTS_tmp - 1.0) - 1;
    acoef = b_xw->size[0];
    b_xw->size[0] = (int)(halfNPTS_tmp - 1.0) - 1;
    emxEnsureCapacity_real_T(b_xw, acoef);
    b_xw_data = b_xw->data;
    for (k = 0; k <= nFullPasses - 2; k++) {
      b_xw_data[k] = 2.0 * Px_data[k + 1];
    }
    for (k = 0; k < b_n2; k++) {
      Px_data[k + 1] = b_xw_data[k];
    }
  }
  emxFree_real_T(&b_xw);
  emxFree_real_T(&xw);
  b_n2 = b_select->size[1];
  acoef = w->size[0];
  w->size[0] = b_select->size[1];
  emxEnsureCapacity_real_T(w, acoef);
  wrappedData_data = w->data;
  for (k = 0; k < b_n2; k++) {
    wrappedData_data[k] = costab1q_data[(int)select_data[k] - 1];
  }
  emxFree_real_T(&costab1q);
  emxFree_real_T(&b_select);
  if (!Fs_tmp) {
    for (k = 0; k < b_n2; k++) {
      Px_data[k] /= varargin_3;
    }
  } else {
    for (k = 0; k < b_n2; k++) {
      Px_data[k] /= 6.2831853071795862;
    }
  }
}

/* End of code generation (periodogram.c) */
