/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_predict_exercise_index_info.c
 *
 * Code generation for function 'predict_exercise_index'
 *
 */

/* Include files */
#include "_coder_predict_exercise_index_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789cdd56cd6e133110764a415c2801249ea042aa1051080855bd954d09a9d424ca8f2a14"
      "5789b33bdb3af1da2bdba936574edc781dc489230fc09107e0259048"
      "36717e56acb66aca56642eb3b39fed6f66acf96494299f6410423b686ad94753ffc0c433"
      "bf85562d8a6766fe4e243676176dafec33f8e799b705d710e869c089",
      "07f39d8ef028275c37473e20094ab04b7042c4a50c9ad483c672509944debb25681e4ca0"
      "c9b77501f6a031f490bc508b0cd97230ef4737a6deed847e442dda8f"
      "e83ac3175c93cf9cff3481cfe0be0487daba0301489b2ae850ee40b07edd86f75e6c1e53"
      "c411c31e8305dff735f92012a3c83a83b78fceac03dc5220157698ee",
      "4b5ce55094f4127011d4400b1f9f538d6b52f4c1d62f4aefb1473423bd0ee1848d145538"
      "5fe8285b525f2bfcf726e63c94dcc78757ac2bea17ebef87fef1decf"
      "104a8b6fcfcd7e4c93cfd86df1a5358ffd062f9de749fe8dac06ac5178553f1c1d1e1517"
      "79d4127892f24031715ae77763f6ff2b1ddd74be6fd7e433e7b713f8",
      "0cde6edda05eda0c083f110eb0dc78d54a3ddd987c6f6aae9fa4ac93bf5eee6ca5c9676c"
      "d375b2e6d58fddeae8d47e5b1ff0aae758fb25d7dd209dfc12b3ffaa"
      "7d6cc59c9f8de0edb275b63b1d552984dec55a08d61301569a84934a9492708e9f2fbec6"
      "c32b39e5937fe31196d8129e4f6c5d9b3e82845c79f77c5ab38e6709",
      "7518dca49733d9e5c2e4869a32956b4ac2952ba4777b3abdee7d3612f80cde2e57d6bccf"
      "b06578deb2f036d3d39383af3f52d567847fb354f966b6e9fa7c4c9a"
      "cd21714e65afa2fdd71ff6837c4148ebffd7e73f905f08b8",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4392U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("predict_exercise_index"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\Users\\dltjr\\OneDrive\\Desktop\\git\\Project-GH\\matlab_"
          "analysis\\02_scripts\\predict_exercise_index.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739879.50506944442));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2973910 (R2025a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("cXaA61UNyO4PRAAvD9qUH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_predict_exercise_index_info.c) */
