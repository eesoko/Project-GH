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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void predict_exercise(real_T input_features[32]);

void predict_exercise_api(const mxArray *prhs);

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
