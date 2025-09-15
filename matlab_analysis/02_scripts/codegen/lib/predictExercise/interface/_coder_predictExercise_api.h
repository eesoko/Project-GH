//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_predictExercise_api.h
//
// Code generation for function 'predictExercise'
//

#ifndef _CODER_PREDICTEXERCISE_API_H
#define _CODER_PREDICTEXERCISE_API_H

// Include files
#include "coder_array_mex.h"
#include "coder_bounded_array.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct cell_wrap_3 {
  coder::bounded_array<char_T, 18U, 2U> f1;
};

struct categorical_tag_1 {
  uint8_T codes;
  cell_wrap_3 categoryNames[6];
};
using categorical = categorical_tag_1;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void predictExercise(coder::array<real_T, 2U> *sensorData,
                     categorical *predictedExercise);

void predictExercise_api(const mxArray *prhs, const mxArray **plhs);

void predictExercise_atexit();

void predictExercise_initialize();

void predictExercise_terminate();

void predictExercise_xil_shutdown();

void predictExercise_xil_terminate();

#endif
// End of code generation (_coder_predictExercise_api.h)
