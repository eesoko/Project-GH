//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_predictExercise_api.cpp
//
// Code generation for function 'predictExercise'
//

// Include files
#include "_coder_predictExercise_api.h"
#include "_coder_predictExercise_mex.h"
#include "coder_array_mex.h"
#include "coder_bounded_array.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131674U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "predictExercise",                                    // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const categorical &u);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 6};
  int32_T iv[2];
  boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const categorical &u)
{
  const mxArray *propValues[5];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  const char_T *propClasses[5]{
      "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
      "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
      "matlab.internal.coder.categorical"};
  const char_T *propNames[5]{"codes", "categoryNames", "isProtected",
                             "isOrdinal", "numCategoriesUpperBound"};
  y = nullptr;
  m = nullptr;
  m1 = nullptr;
  m2 = nullptr;
  m3 = nullptr;
  m4 = nullptr;
  emlrtAssign(&y, emlrtCreateClassInstance2022a(
                      (emlrtCTX)&sp, "matlab.internal.coder.categorical"));
  m = nullptr;
  b_y = nullptr;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *static_cast<uint8_T *>(emlrtMxGetData(m5)) = u.codes;
  emlrtAssign(&b_y, m5);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = nullptr;
  c_y = nullptr;
  i = 6;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, &i));
  for (int32_T i1{0}; i1 < 6; i1++) {
    d_y = nullptr;
    iv[0] = 1;
    i = u.categoryNames[i1].f1.size[1];
    iv[1] = i;
    m5 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, i, m5,
                             &u.categoryNames[i1].f1.data[0]);
    emlrtAssign(&d_y, m5);
    emlrtSetCell(c_y, i1, d_y);
  }
  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = nullptr;
  e_y = nullptr;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&e_y, m5);
  emlrtAssign(&m2, e_y);
  propValues[2] = m2;
  m3 = nullptr;
  f_y = nullptr;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&f_y, m5);
  emlrtAssign(&m3, f_y);
  propValues[3] = m3;
  m4 = nullptr;
  g_y = nullptr;
  m5 = emlrtCreateDoubleScalar(6.0);
  emlrtAssign(&g_y, m5);
  emlrtAssign(&m4, g_y);
  propValues[4] = m4;
  emlrtSetAllProperties((emlrtCTX)&sp, &y, 0, 5, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(&y,
              emlrtConvertInstanceToRedirectSource(
                  (emlrtCTX)&sp, y, 0, "matlab.internal.coder.categorical"));
  return y;
}

void predictExercise_api(const mxArray *prhs, const mxArray **plhs)
{
  coder::array<real_T, 2U> sensorData;
  categorical predictedExercise;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  sensorData.set_owner(false);
  emlrt_marshallIn(st, emlrtAlias(prhs), "sensorData", sensorData);
  // Invoke the target function
  predictExercise(sensorData, &predictedExercise);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(st, predictedExercise);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void predictExercise_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                    (void *)&emlrtExitTimeCleanupDtorFcn,
                                    nullptr, nullptr, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  predictExercise_xil_terminate();
  predictExercise_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void predictExercise_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void predictExercise_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (_coder_predictExercise_api.cpp)
