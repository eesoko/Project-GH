/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_predict_exercise_api.h
 *
 * Code generation for function 'predict_exercise'
 *
 */

#ifndef _CODER_PREDICT_EXERCISE_API_H
#define _CODER_PREDICT_EXERCISE_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x18
#define struct_emxArray_char_T_1x18
struct emxArray_char_T_1x18 {
  char_T data[18];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x18 */
#ifndef typedef_emxArray_char_T_1x18
#define typedef_emxArray_char_T_1x18
typedef struct emxArray_char_T_1x18 emxArray_char_T_1x18;
#endif /* typedef_emxArray_char_T_1x18 */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_char_T_1x18 f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_categorical
#define typedef_categorical
typedef struct {
  uint8_T codes;
  cell_wrap_0 categoryNames[6];
} categorical;
#endif /* typedef_categorical */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void predict_exercise(real_T input_features[32], categorical *label);

void predict_exercise_api(const mxArray *prhs, const mxArray **plhs);

void predict_exercise_atexit(void);

void predict_exercise_initialize(void);

void predict_exercise_terminate(void);

void predict_exercise_xil_shutdown(void);

void predict_exercise_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_predict_exercise_api.h) */
