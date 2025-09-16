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
  const char_T *data[7] = {
      "789ced573b6f1341103ea3806802aef20ba2504498101e8274c18e9303d90eb29d87bcc1"
      "59df6d9c4df671d95d5b672a4a3af82994882a2d0505120505353f00"
      "6891b0cfb776bcd271511c2e8ac53473e36f77be9dd99b4f672b6517529665ddb0faf66e"
      "a6efa7c3381dfa2bd6a899782af45346aced6a884c1bf89bd03b9c29",
      "e4ab7ec02045839d2ea79841a62a1d0f5902494edac80d903d4c500553543e19147b11cd"
      "9f8006410fea3d67f79173586e514beccbe109c9c960d08fdd887aa7"
      "ac513371d3cc7e98eb349f7746be54446cf269ef09e46247d5918f8483251ab75ecd772d"
      "92bf8fb8bcd5206858eff1987cf548be51bcb6b2935d02558984042e",
      "5107029418ca09dc462087e4a1e21e686205d6053f408ebabdba0628540436ea9041d291"
      "588285c5ba7404f6940466f33234f67db979ca7a4c3f5c7f3df03fe6"
      "be0550527cb73e7d3f4a924fdb45f1f911f94efb3ece44f0a50dbce3f0655ababb9ce7cd"
      "2a7db89fcf71fbf993d5e139d66378e2ce6145c449e5df8dd8ffaf74",
      "73d2f98ecfc8a7f3bf88e1d378ad7a8e3ae910045979a350e02e2299eec2e4e6fa67c23a"
      "09ed57bf92e4d336e93a597565966c3ddec6c27ee9970573e04a07e7"
      "274727df47ec3f6d1f3722f2a70dbc66677766fba32a3857b340714e1adc0752c16052a1"
      "940235c1fcf0a93bbc8261d6fbad3bbf02ccd3de18832ca71e745477",
      "acbb9f3d833ade8e59c79d983a34ae8f97d1a7cb04876b294c6446b669e619120c917c8b"
      "390a737669f57a27864fe335bb38e6bd06ad03f3ddde81d1def5ae37"
      "317df96c7f4954afadaf1f1f24ca17daa4ebf5a65fed6caf1ddd836ed1a7255b6c319b14"
      "72fff55ae7ab46e44f1bf839e87528d4ebfd3fab5c8cccf3eb31eb98",
      "8ba943e37fd5eb8a804cee71412feebb7adcfb2cc7f069fcbc747ad0b2e03693d393a50f"
      "09eb33f84d12e50b6dd2f5f929ac545ad0dd148da2f2ee6f3ff21716"
      "b9c85e7e7dfe03282978bb",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 5832U, &nameCaptureInfo);
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
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "ResolvedFilePath",
                emlrtMxCreateString(
                    "C:\\Users\\dltjr\\OneDrive\\Desktop\\git\\Project-"
                    "GH\\matlab_analysis\\02_scripts\\predict_exercise.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739876.80050925922));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2973910 (R2025a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("905S7T95ZqoT9osBLkfCeC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_predict_exercise_info.c) */
