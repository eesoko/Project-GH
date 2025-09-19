/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_predict_exercise_index_api.h
 *
 * Code generation for function 'predict_exercise_index'
 *
 */

#ifndef _CODER_PREDICT_EXERCISE_INDEX_API_H
#define _CODER_PREDICT_EXERCISE_INDEX_API_H

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
int32_T predict_exercise_index(real_T features[32]);

void predict_exercise_index_api(const mxArray *prhs, const mxArray **plhs);

void predict_exercise_index_atexit(void);

void predict_exercise_index_initialize(void);

void predict_exercise_index_terminate(void);

void predict_exercise_index_xil_shutdown(void);

void predict_exercise_index_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_predict_exercise_index_api.h) */
