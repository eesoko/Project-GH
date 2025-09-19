/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlascl.c
 *
 * Code generation for function 'xzlascl'
 *
 */

/* Include files */
#include "xzlascl.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void b_xzlascl(double cfrom, double cto, int m, emxArray_real_T *A, int lda)
{
  double cfromc;
  double ctoc;
  double *A_data;
  int i;
  int j;
  bool notdone;
  A_data = A->data;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (j = 0; j < 3; j++) {
      int offset;
      offset = j * lda - 1;
      for (i = 0; i < m; i++) {
        int b_i;
        b_i = (offset + i) + 1;
        A_data[b_i] *= mul;
      }
    }
  }
}

void xzlascl(double cfrom, double cto, int m, double A_data[])
{
  double cfromc;
  double ctoc;
  int b_i;
  bool notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    int i;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    i = (unsigned char)m;
    for (b_i = 0; b_i < i; b_i++) {
      A_data[b_i] *= mul;
    }
  }
}

/* End of code generation (xzlascl.c) */
