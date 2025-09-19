/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strtrim.c
 *
 * Code generation for function 'strtrim'
 *
 */

/* Include files */
#include "strtrim.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void strtrim(const char x_data[], const int x_size[2], char y_data[],
             int y_size[2])
{
  static const boolean_T bv[128] = {
      false, false, false, false, false, false, false, false, false, true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false};
  int b_j1;
  int i;
  int j2;
  b_j1 = 0;
  while ((b_j1 + 1 <= x_size[1]) && bv[(int)x_data[b_j1]]) {
    b_j1++;
  }
  j2 = x_size[1];
  while ((j2 > 0) && bv[(int)x_data[j2 - 1]]) {
    j2--;
  }
  if (b_j1 + 1 > j2) {
    b_j1 = 0;
    j2 = 0;
  }
  y_size[0] = 1;
  j2 -= b_j1;
  y_size[1] = j2;
  for (i = 0; i < j2; i++) {
    y_data[i] = x_data[b_j1 + i];
  }
}

/* End of code generation (strtrim.c) */
