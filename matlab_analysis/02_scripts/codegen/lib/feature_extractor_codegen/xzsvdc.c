/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "feature_extractor_codegen_emxutil.h"
#include "feature_extractor_codegen_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
int xzsvdc(emxArray_real_T *A, emxArray_real_T *U, double S_data[],
           double V_data[], int V_size[2])
{
  emxArray_real_T *work;
  double Vf[9];
  double e[3];
  double s_data[3];
  double anrm;
  double b;
  double cscale;
  double f;
  double nrm;
  double sm;
  double sqds;
  double *A_data;
  double *U_data;
  double *work_data;
  int S_size;
  int j;
  int k;
  int n;
  int ns;
  int q;
  bool doscale;
  A_data = A->data;
  n = A->size[0];
  ns = A->size[0] + 1;
  if (ns > 3) {
    ns = 3;
  }
  S_size = A->size[0];
  if (S_size > 3) {
    S_size = 3;
  }
  if (ns - 1 >= 0) {
    memset(&s_data[0], 0, (unsigned int)ns * sizeof(double));
  }
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  emxInit_real_T(&work, 1);
  ns = work->size[0];
  work->size[0] = A->size[0];
  emxEnsureCapacity_real_T(work, ns);
  work_data = work->data;
  for (j = 0; j < n; j++) {
    work_data[j] = 0.0;
  }
  ns = U->size[0] * U->size[1];
  U->size[0] = A->size[0];
  U->size[1] = S_size;
  emxEnsureCapacity_real_T(U, ns);
  U_data = U->data;
  ns = A->size[0] * S_size;
  for (j = 0; j < ns; j++) {
    U_data[j] = 0.0;
  }
  memset(&Vf[0], 0, 9U * sizeof(double));
  doscale = false;
  cscale = 0.0;
  anrm = xzlangeM(A);
  if (A->size[0] == 0) {
    Vf[0] = 1.0;
    Vf[4] = 1.0;
    Vf[8] = 1.0;
  } else {
    double rt;
    double snorm;
    int m;
    int nct;
    int nctp1;
    int nmq;
    int nrt;
    int qp1;
    int qq;
    int temp_tmp_tmp;
    bool guard1;
    cscale = anrm;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      doscale = true;
      cscale = 6.7178761075670888E-139;
      guard1 = true;
    } else if (anrm > 1.4885657073574029E+138) {
      doscale = true;
      cscale = 1.4885657073574029E+138;
      guard1 = true;
    }
    if (guard1) {
      b_xzlascl(anrm, cscale, A->size[0], A, A->size[0]);
      A_data = A->data;
    }
    nrt = (A->size[0] >= 1);
    if (A->size[0] >= 1) {
      nct = A->size[0] - 1;
    } else {
      nct = 0;
    }
    if (nct > 3) {
      nct = 3;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      temp_tmp_tmp = nct;
    } else {
      temp_tmp_tmp = 1;
    }
    for (q = 0; q < temp_tmp_tmp; q++) {
      bool apply_transform;
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = xnrm2(nmq + 1, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            ns = qq + nmq;
            for (j = qq; j <= ns; j++) {
              A_data[j - 1] *= nrm;
            }
          } else {
            ns = qq + nmq;
            for (j = qq; j <= ns; j++) {
              A_data[j - 1] /= s_data[q];
            }
          }
          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (j = qp1; j < 4; j++) {
        ns = q + n * (j - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (nmq >= 0) {
            for (k = 0; k <= nmq; k++) {
              nrm += A_data[(qq + k) - 1] * A_data[ns + k];
            }
          }
          nrm = -(nrm / A_data[q + A->size[0] * q]);
          xaxpy(nmq + 1, nrm, qq, A, ns + 1);
          A_data = A->data;
        }
        e[j - 1] = A_data[ns];
      }
      if (q + 1 <= nct) {
        for (j = q + 1; j <= n; j++) {
          U_data[(j + U->size[0] * q) - 1] = A_data[(j + A->size[0] * q) - 1];
        }
      }
      if (q + 1 <= nrt) {
        nrm = b_xnrm2(e);
        if (nrm == 0.0) {
          e[0] = 0.0;
        } else {
          if (e[1] < 0.0) {
            e[0] = -nrm;
          } else {
            e[0] = nrm;
          }
          nrm = e[0];
          if (fabs(e[0]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e[0];
            for (j = qp1; j < 4; j++) {
              e[j - 1] *= nrm;
            }
          } else {
            for (j = qp1; j < 4; j++) {
              e[j - 1] /= nrm;
            }
          }
          e[1]++;
          e[0] = -e[0];
          if (n >= 2) {
            for (j = qp1; j <= n; j++) {
              work_data[j - 1] = 0.0;
            }
            for (j = qp1; j < 4; j++) {
              c_xaxpy(nmq, e[j - 1], A, n * (j - 1) + 2, work);
              work_data = work->data;
            }
            for (j = qp1; j < 4; j++) {
              d_xaxpy(nmq, -e[j - 1] / e[1], work, A, n * (j - 1) + 2);
              A_data = A->data;
            }
          }
        }
        for (j = qp1; j < 4; j++) {
          Vf[j - 1] = e[j - 1];
        }
      }
    }
    if (A->size[0] + 1 >= 3) {
      m = 3;
    } else {
      m = A->size[0] + 1;
    }
    if (nct < 3) {
      s_data[nct] = A_data[nct + A->size[0] * nct];
    }
    if (A->size[0] < m) {
      s_data[m - 1] = 0.0;
    }
    if (nrt + 1 < m) {
      e[nrt] = A_data[nrt + A->size[0] * (m - 1)];
    }
    e[m - 1] = 0.0;
    if (nct + 1 <= S_size) {
      for (j = nctp1; j <= S_size; j++) {
        for (k = 0; k < n; k++) {
          U_data[k + U->size[0] * (j - 1)] = 0.0;
        }
        U_data[(j + U->size[0] * (j - 1)) - 1] = 1.0;
      }
    }
    for (q = nct; q >= 1; q--) {
      qp1 = q + 1;
      nmq = n - q;
      qq = (q + n * (q - 1)) - 1;
      if (s_data[q - 1] != 0.0) {
        for (j = qp1; j <= S_size; j++) {
          ns = q + n * (j - 1);
          nrm = 0.0;
          if (nmq >= 0) {
            for (k = 0; k <= nmq; k++) {
              nrm += U_data[qq + k] * U_data[(ns + k) - 1];
            }
          }
          nrm = -(nrm / U_data[qq]);
          xaxpy(nmq + 1, nrm, qq + 1, U, ns);
          U_data = U->data;
        }
        for (j = q; j <= n; j++) {
          U_data[(j + U->size[0] * (q - 1)) - 1] =
              -U_data[(j + U->size[0] * (q - 1)) - 1];
        }
        U_data[qq]++;
        for (j = 0; j <= q - 2; j++) {
          U_data[j + U->size[0] * (q - 1)] = 0.0;
        }
      } else {
        for (j = 0; j < n; j++) {
          U_data[j + U->size[0] * (q - 1)] = 0.0;
        }
        U_data[qq] = 1.0;
      }
    }
    for (j = 2; j >= 0; j--) {
      if ((j + 1 <= nrt) && (e[0] != 0.0)) {
        b_xaxpy(-(xdotc(Vf, Vf, 5) / Vf[1]), Vf, 5);
        b_xaxpy(-(xdotc(Vf, Vf, 8) / Vf[1]), Vf, 8);
      }
      Vf[3 * j] = 0.0;
      Vf[3 * j + 1] = 0.0;
      Vf[3 * j + 2] = 0.0;
      Vf[j + 3 * j] = 1.0;
    }
    temp_tmp_tmp = (unsigned char)m;
    for (k = 0; k < temp_tmp_tmp; k++) {
      nrm = s_data[k];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm /= rt;
        s_data[k] = rt;
        if (k + 1 < m) {
          e[k] /= nrm;
        }
        if (k + 1 <= n) {
          ns = n * k;
          qq = ns + n;
          for (j = ns + 1; j <= qq; j++) {
            U_data[j - 1] *= nrm;
          }
        }
      }
      if (k + 1 < m) {
        nrm = e[k];
        if (nrm != 0.0) {
          rt = fabs(nrm);
          nrm = rt / nrm;
          e[k] = rt;
          s_data[k + 1] *= nrm;
          ns = 3 * (k + 1);
          qq = ns + 3;
          for (j = ns + 1; j <= qq; j++) {
            Vf[j - 1] *= nrm;
          }
        }
      }
    }
    nrt = m;
    nmq = 0;
    snorm = 0.0;
    for (j = 0; j < temp_tmp_tmp; j++) {
      snorm = fmax(snorm, fmax(fabs(s_data[j]), fabs(e[j])));
    }
    while ((m > 0) && (nmq < 75)) {
      bool exitg1;
      nct = m - 1;
      exitg1 = false;
      while (!(exitg1 || (nct == 0))) {
        nrm = fabs(e[nct - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(s_data[nct - 1]) + fabs(s_data[nct]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((nmq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[nct - 1] = 0.0;
          exitg1 = true;
        } else {
          nct--;
        }
      }
      if (nct == m - 1) {
        ns = 4;
      } else {
        qq = m;
        ns = m;
        exitg1 = false;
        while ((!exitg1) && (ns >= nct)) {
          qq = ns;
          if (ns == nct) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m) {
              nrm = fabs(e[ns - 1]);
            }
            if (ns > nct + 1) {
              nrm += fabs(e[ns - 2]);
            }
            rt = fabs(s_data[ns - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s_data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (qq == nct) {
          ns = 3;
        } else if (qq == m) {
          ns = 1;
        } else {
          ns = 2;
          nct = qq;
        }
      }
      switch (ns) {
      case 1:
        f = e[m - 2];
        e[m - 2] = 0.0;
        ns = m - 1;
        for (j = ns; j >= nct + 1; j--) {
          rt = xrotg(&s_data[j - 1], &f, &nrm);
          if (j > nct + 1) {
            f = -nrm * e[0];
            e[0] *= rt;
          }
          xrot(Vf, 3 * (j - 1) + 1, 3 * (m - 1) + 1, rt, nrm);
        }
        break;
      case 2:
        f = e[nct - 1];
        e[nct - 1] = 0.0;
        for (j = nct + 1; j <= m; j++) {
          sqds = xrotg(&s_data[j - 1], &f, &b);
          nrm = e[j - 1];
          f = -b * nrm;
          e[j - 1] = nrm * sqds;
          if (n >= 1) {
            ns = n * (j - 1);
            nctp1 = n * (nct - 1);
            for (k = 0; k < n; k++) {
              qq = nctp1 + k;
              nrm = U_data[qq];
              temp_tmp_tmp = ns + k;
              rt = U_data[temp_tmp_tmp];
              U_data[qq] = sqds * nrm - b * rt;
              U_data[temp_tmp_tmp] = sqds * rt + b * nrm;
            }
          }
        }
        break;
      case 3: {
        double scale;
        nrm = s_data[m - 1];
        rt = s_data[m - 2];
        b = e[m - 2];
        scale = fmax(
            fmax(fmax(fmax(fabs(nrm), fabs(rt)), fabs(b)), fabs(s_data[nct])),
            fabs(e[nct]));
        sm = nrm / scale;
        nrm = rt / scale;
        rt = b / scale;
        sqds = s_data[nct] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = sqrt(b * b + nrm);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        f = (sqds + sm) * (sqds - sm) + rt;
        sqds *= e[nct] / scale;
        for (j = nct + 1; j < m; j++) {
          b = xrotg(&f, &sqds, &sm);
          if (j > nct + 1) {
            e[0] = f;
          }
          nrm = e[j - 1];
          rt = s_data[j - 1];
          e[j - 1] = b * nrm - sm * rt;
          sqds = sm * s_data[j];
          s_data[j] *= b;
          xrot(Vf, 3 * (j - 1) + 1, 3 * j + 1, b, sm);
          s_data[j - 1] = b * rt + sm * nrm;
          b = xrotg(&s_data[j - 1], &sqds, &sm);
          nrm = e[j - 1];
          f = b * nrm + sm * s_data[j];
          s_data[j] = -sm * nrm + b * s_data[j];
          sqds = sm * e[j];
          e[j] *= b;
          if (j < n) {
            ns = n * (j - 1);
            qq = n * j;
            for (k = 0; k < n; k++) {
              temp_tmp_tmp = qq + k;
              nrm = U_data[temp_tmp_tmp];
              nctp1 = ns + k;
              rt = U_data[nctp1];
              U_data[temp_tmp_tmp] = b * nrm - sm * rt;
              U_data[nctp1] = b * rt + sm * nrm;
            }
          }
        }
        e[m - 2] = f;
        nmq++;
      } break;
      default:
        if (s_data[nct] < 0.0) {
          s_data[nct] = -s_data[nct];
          ns = 3 * nct;
          qq = ns + 3;
          for (j = ns + 1; j <= qq; j++) {
            Vf[j - 1] = -Vf[j - 1];
          }
        }
        qp1 = nct + 1;
        while ((nct + 1 < nrt) && (s_data[nct] < s_data[qp1])) {
          rt = s_data[nct];
          s_data[nct] = s_data[qp1];
          s_data[qp1] = rt;
          xswap(Vf, 3 * nct + 1, 3 * (nct + 1) + 1);
          if (nct + 1 < n) {
            nctp1 = n * nct;
            ns = n * (nct + 1);
            for (j = 0; j < n; j++) {
              qq = nctp1 + j;
              nrm = U_data[qq];
              temp_tmp_tmp = ns + j;
              U_data[qq] = U_data[temp_tmp_tmp];
              U_data[temp_tmp_tmp] = nrm;
            }
          }
          nct = qp1;
          qp1++;
        }
        nmq = 0;
        m--;
        break;
      }
    }
  }
  emxFree_real_T(&work);
  if (S_size - 1 >= 0) {
    memcpy(&S_data[0], &s_data[0], (unsigned int)S_size * sizeof(double));
  }
  if (doscale) {
    xzlascl(cscale, anrm, S_size, S_data);
  }
  V_size[0] = 3;
  V_size[1] = S_size;
  for (j = 0; j < S_size; j++) {
    V_data[3 * j] = Vf[3 * j];
    ns = 3 * j + 1;
    V_data[ns] = Vf[ns];
    ns = 3 * j + 2;
    V_data[ns] = Vf[ns];
  }
  return S_size;
}

/* End of code generation (xzsvdc.c) */
