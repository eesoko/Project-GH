/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_predict_exercise_info.c
 *
 * Code generation for function 'predict_exercise'
 *
 */

/* Include files */
#include "_coder_predict_exercise_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789cdd56cd6ed34010de4041bd00b9c0135415125214452055bd9114dad0240492006db6"
      "4a36f6846eb3ebb57637a9f306dc100f838438f1101c79041e800b12"
      "89edcd8f25cb510346e95cc6e36f77bf99b1e7d3a24cb99a4108dd4581fdca06fe4e1887"
      "21ba81962d8a67427f33121bbb85b696f619fc63e82de168f0741038",
      "84c36ca72d387588a39b6317900425d8086c1fe953064dcaa1b118d4a6117fbe00cd8229"
      "347d2e9d8335680c3992e76a9e215b0c66fde8c6d4bb95d08fa845fb"
      "115d67f8dc2bf26562e2289ff1ae049b5aba031e488b2a58b75ec3773b963f406c31ec31"
      "98d7fb6d4dbed358be65bcfdecacb48f5b0aa4c20d1083235101c007",
      "a0065ab8f8906a5c97e202261d393cc29c68467a1de210365654e17ca1a32c495dad70b4"
      "6f391e9c9fd4bf7b2bd613f5f3f5dbbeaf3ffc914993af9b3ff99426"
      "9fb1ffc5e7c59cb7eafff820862f1bc10bafd4f89dac78a36abfca0f9ee42bbdc6252dce"
      "f3a827f024e58162e2b4ceefc6ecff57ba79ddf9be5c91cf9cff2681",
      "cfe0edd6dfd1498b0171aac206969bac4a6f9e79cafaf8f96765374d3e639baa8ff763f8"
      "b211fc72507c591995d5293d96af8b7cefa9a35b45747df471dd796e"
      "c59c9f8de0ed72e96c2798532984dec15a08d6131e569af8634a9492f01e3f9a3f4d2657"
      "3ad499be9bccafc425c15d62e97a70f311d2bff2983a3eac59c76e42",
      "1d0637e9e54c76393fb9a1a64ce59a9238aa2f24df5c7d6e24f019bc5daeadf93dfd96e1"
      "59cbc20b6c5a7ab2fff57baafa8cf06f962a5f689baacfabde5f5f90"
      "667348ecb7b257d3eee3933d2f5f10b2b4f9fafc07b5200263",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4368U, &nameCaptureInfo);
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
                emlrtMxCreateString("predict_exercise"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "ResolvedFilePath",
                emlrtMxCreateString(
                    "C:\\Users\\SeokHoLee\\Desktop\\Git\\Project_GH\\matlab_"
                    "analysis\\02_scripts\\predict_exercise.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739878.54098379635));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2973910 (R2025a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("5QR6ubdVaC7zOglyaMntZH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_predict_exercise_info.c) */
