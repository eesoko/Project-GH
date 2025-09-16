/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_feature_extractor_codegen_mex.h
 *
 * Code generation for function 'feature_extractor_codegen'
 *
 */

#ifndef _CODER_FEATURE_EXTRACTOR_CODEGEN_MEX_H
#define _CODER_FEATURE_EXTRACTOR_CODEGEN_MEX_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_feature_extractor_codegen_mexFunction(int32_T nlhs,
                                                  mxArray *plhs[1],
                                                  int32_T nrhs,
                                                  const mxArray *prhs[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_feature_extractor_codegen_mex.h) */
