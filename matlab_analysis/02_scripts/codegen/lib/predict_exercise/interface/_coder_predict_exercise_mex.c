/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_predict_exercise_mex.c
 *
 * Code generation for function 'predict_exercise'
 *
 */

/* Include files */
#include "_coder_predict_exercise_mex.h"
#include "_coder_predict_exercise_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  mexAtExit(&predict_exercise_atexit);
  predict_exercise_initialize();
  unsafe_predict_exercise_mexFunction(nlhs, nrhs, prhs);
  predict_exercise_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-949", true);
  return emlrtRootTLSGlobal;
}

void unsafe_predict_exercise_mexFunction(int32_T nlhs, int32_T nrhs,
                                         const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        16, "predict_exercise");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "predict_exercise");
  }
  /* Call the function. */
  predict_exercise_api(prhs[0]);
}

/* End of code generation (_coder_predict_exercise_mex.c) */
