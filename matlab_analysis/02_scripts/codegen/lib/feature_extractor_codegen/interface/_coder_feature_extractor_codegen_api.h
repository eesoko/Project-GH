/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_feature_extractor_codegen_api.h
 *
 * Code generation for function 'feature_extractor_codegen'
 *
 */

#ifndef _CODER_FEATURE_EXTRACTOR_CODEGEN_API_H
#define _CODER_FEATURE_EXTRACTOR_CODEGEN_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void feature_extractor_codegen(emxArray_real_T *raw_data, real_T Fs_actual,
                               real_T features[32]);

void feature_extractor_codegen_api(const mxArray *const prhs[2],
                                   const mxArray **plhs);

void feature_extractor_codegen_atexit(void);

void feature_extractor_codegen_initialize(void);

void feature_extractor_codegen_terminate(void);

void feature_extractor_codegen_xil_shutdown(void);

void feature_extractor_codegen_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_feature_extractor_codegen_api.h) */
