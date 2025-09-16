/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationModel.c
 *
 * Code generation for function 'CompactClassificationModel'
 *
 */

/* Include files */
#include "CompactClassificationModel.h"
#include "introsort.h"
#include "predict_exercise_types.h"
#include "rt_nonfinite.h"
#include "strtrim.h"
#include "rt_nonfinite.h"

/* Function Definitions */
unsigned char
c_CompactClassificationModel_ma(const double obj_Prior[6],
                                const double scores[6],
                                cell_wrap_0 labels_categoryNames[6])
{
  static const char cv4[18] = {'S', 'i', 'd', 'e', ' ', 'L', 'a', 't', 'e',
                               'r', 'a', 'l', ' ', 'R', 'a', 'i', 's', 'e'};
  static const char cv2[14] = {'O', 'v', 'e', 'r', 'h', 'e', 'a',
                               'd', ' ', 'P', 'r', 'e', 's', 's'};
  static const char cv[13] = {'D', 'u', 'm', 'b', 'b', 'e', 'l',
                              'l', ' ', 'C', 'u', 'r', 'l'};
  static const char a[11] = {'<', 'u', 'n', 'd', 'e', 'f',
                             'i', 'n', 'e', 'd', '>'};
  static const char cv3[7] = {'P', 'u', 's', 'h', ' ', 'U', 'p'};
  static const char cv1[5] = {'L', 'u', 'n', 'g', 'e'};
  static const char cv5[5] = {'S', 'q', 'u', 'a', 't'};
  cell_wrap_0 names[7];
  cell_wrap_0 b_names[6];
  cell_wrap_0 this_workspace_c[6];
  cell_wrap_0 inData;
  cell_wrap_0 tempnames;
  double b_d;
  double ex;
  int unusedExpr[6];
  int b_k;
  int iindx;
  int k;
  int nb;
  boolean_T d[6];
  boolean_T exitg1;
  boolean_T y;
  for (k = 0; k < 6; k++) {
    d[k] = rtIsNaN(scores[k]);
  }
  y = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= 5)) {
    if (!d[b_k]) {
      y = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }
  ex = obj_Prior[0];
  iindx = 1;
  for (k = 0; k < 5; k++) {
    b_d = obj_Prior[k + 1];
    if (ex < b_d) {
      ex = b_d;
      iindx = k + 2;
    }
  }
  names[0].f1.size[0] = 1;
  names[0].f1.size[1] = 11;
  for (k = 0; k < 11; k++) {
    names[0].f1.data[k] = a[k];
  }
  names[1].f1.size[0] = 1;
  names[1].f1.size[1] = 13;
  for (k = 0; k < 13; k++) {
    names[1].f1.data[k] = cv[k];
  }
  names[2].f1.size[0] = 1;
  names[2].f1.size[1] = 5;
  for (k = 0; k < 5; k++) {
    names[2].f1.data[k] = cv1[k];
  }
  names[3].f1.size[0] = 1;
  names[3].f1.size[1] = 14;
  for (k = 0; k < 14; k++) {
    names[3].f1.data[k] = cv2[k];
  }
  names[4].f1.size[0] = 1;
  names[4].f1.size[1] = 7;
  for (k = 0; k < 7; k++) {
    names[4].f1.data[k] = cv3[k];
  }
  names[5].f1.size[0] = 1;
  names[5].f1.size[1] = 18;
  for (k = 0; k < 18; k++) {
    names[5].f1.data[k] = cv4[k];
  }
  names[6].f1.size[0] = 1;
  names[6].f1.size[1] = 5;
  for (k = 0; k < 5; k++) {
    names[6].f1.data[k] = cv5[k];
  }
  tempnames.f1.size[0] = 1;
  b_k = names[iindx].f1.size[1];
  tempnames.f1.size[1] = b_k;
  for (k = 0; k < b_k; k++) {
    tempnames.f1.data[k] = names[iindx].f1.data[k];
  }
  b_names[0].f1.size[0] = 1;
  b_names[0].f1.size[1] = 13;
  for (k = 0; k < 13; k++) {
    b_names[0].f1.data[k] = cv[k];
  }
  b_names[1].f1.size[0] = 1;
  b_names[1].f1.size[1] = 5;
  for (k = 0; k < 5; k++) {
    b_names[1].f1.data[k] = cv1[k];
  }
  b_names[2].f1.size[0] = 1;
  b_names[2].f1.size[1] = 14;
  for (k = 0; k < 14; k++) {
    b_names[2].f1.data[k] = cv2[k];
  }
  b_names[3].f1.size[0] = 1;
  b_names[3].f1.size[1] = 7;
  for (k = 0; k < 7; k++) {
    b_names[3].f1.data[k] = cv3[k];
  }
  b_names[4].f1.size[0] = 1;
  b_names[4].f1.size[1] = 18;
  for (k = 0; k < 18; k++) {
    b_names[4].f1.data[k] = cv4[k];
  }
  b_names[5].f1.size[0] = 1;
  b_names[5].f1.size[1] = 5;
  for (k = 0; k < 5; k++) {
    b_names[5].f1.data[k] = cv5[k];
  }
  if (!y) {
    if (!rtIsNaN(scores[0])) {
      iindx = 1;
    } else {
      iindx = 0;
      b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (b_k < 7)) {
        if (!rtIsNaN(scores[b_k - 1])) {
          iindx = b_k;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    if (iindx == 0) {
      nb = 0;
    } else {
      ex = scores[iindx - 1];
      nb = iindx - 1;
      b_k = iindx + 1;
      for (k = b_k; k < 7; k++) {
        b_d = scores[k - 1];
        if (ex < b_d) {
          ex = b_d;
          nb = k - 1;
        }
      }
    }
    tempnames.f1.size[0] = 1;
    b_k = b_names[nb].f1.size[1];
    tempnames.f1.size[1] = b_k;
    for (k = 0; k < b_k; k++) {
      tempnames.f1.data[k] = b_names[nb].f1.data[k];
    }
  }
  strtrim(tempnames.f1.data, tempnames.f1.size, inData.f1.data, inData.f1.size);
  for (k = 0; k < 6; k++) {
    strtrim(b_names[k].f1.data, b_names[k].f1.size, this_workspace_c[k].f1.data,
            this_workspace_c[k].f1.size);
  }
  introsort(this_workspace_c, unusedExpr);
  labels_categoryNames[0].f1.size[0] = 1;
  b_k = this_workspace_c[0].f1.size[1];
  labels_categoryNames[0].f1.size[1] = this_workspace_c[0].f1.size[1];
  for (k = 0; k < b_k; k++) {
    labels_categoryNames[0].f1.data[k] = this_workspace_c[0].f1.data[k];
  }
  labels_categoryNames[1].f1.size[0] = 1;
  b_k = this_workspace_c[1].f1.size[1];
  labels_categoryNames[1].f1.size[1] = this_workspace_c[1].f1.size[1];
  for (k = 0; k < b_k; k++) {
    labels_categoryNames[1].f1.data[k] = this_workspace_c[1].f1.data[k];
  }
  labels_categoryNames[2].f1.size[0] = 1;
  b_k = this_workspace_c[2].f1.size[1];
  labels_categoryNames[2].f1.size[1] = this_workspace_c[2].f1.size[1];
  for (k = 0; k < b_k; k++) {
    labels_categoryNames[2].f1.data[k] = this_workspace_c[2].f1.data[k];
  }
  labels_categoryNames[3].f1.size[0] = 1;
  b_k = this_workspace_c[3].f1.size[1];
  labels_categoryNames[3].f1.size[1] = this_workspace_c[3].f1.size[1];
  for (k = 0; k < b_k; k++) {
    labels_categoryNames[3].f1.data[k] = this_workspace_c[3].f1.data[k];
  }
  labels_categoryNames[4].f1.size[0] = 1;
  b_k = this_workspace_c[4].f1.size[1];
  labels_categoryNames[4].f1.size[1] = this_workspace_c[4].f1.size[1];
  for (k = 0; k < b_k; k++) {
    labels_categoryNames[4].f1.data[k] = this_workspace_c[4].f1.data[k];
  }
  labels_categoryNames[5].f1.size[0] = 1;
  b_k = this_workspace_c[5].f1.size[1];
  labels_categoryNames[5].f1.size[1] = this_workspace_c[5].f1.size[1];
  for (k = 0; k < b_k; k++) {
    labels_categoryNames[5].f1.data[k] = this_workspace_c[5].f1.data[k];
  }
  b_k = 0;
  iindx = 0;
  exitg1 = false;
  while ((!exitg1) && (iindx < 6)) {
    boolean_T b;
    y = false;
    nb = this_workspace_c[iindx].f1.size[1];
    b = (inData.f1.size[1] == 0);
    if (b && (nb == 0)) {
      y = true;
    } else if (inData.f1.size[1] == nb) {
      int kstr;
      kstr = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (kstr <= nb - 1) {
          if (inData.f1.data[kstr] != this_workspace_c[iindx].f1.data[kstr]) {
            exitg2 = 1;
          } else {
            kstr++;
          }
        } else {
          y = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    if (y) {
      b_k = iindx + 1;
      exitg1 = true;
    } else {
      iindx++;
    }
  }
  return (unsigned char)b_k;
}

/* End of code generation (CompactClassificationModel.c) */
