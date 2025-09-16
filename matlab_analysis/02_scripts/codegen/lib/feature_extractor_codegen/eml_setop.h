/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.h
 *
 * Code generation for function 'eml_setop'
 *
 */

#ifndef EML_SETOP_H
#define EML_SETOP_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int do_vectors(const int a_data[], int a_size, const int b_data[], int b_size,
               int c_data[], int ia_data[], int *ia_size, int ib_data[],
               int *ib_size);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (eml_setop.h) */
