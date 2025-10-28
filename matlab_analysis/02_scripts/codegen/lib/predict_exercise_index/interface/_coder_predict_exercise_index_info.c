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
      "789cdd56c16e13311075a0202e8572e10b2a2484b40aa145556f256d93546d1ab11b108a"
      "abc4d99db44ebcf6ca76da0d5fc08defe00f10273e802347fe827305"
      "c9669da42ba2450d2c6ae6329e7db6dfcc58f3b4285739ca2184eea3d81e8edd6a1caec5"
      "fe16ba6a493c17fbdb89d8d81db472e59cc13fc4de155c43a8c70127",
      "3e4c4e7ac2a79c70ed0c0240129460e7e04548873270a80ff66c501d45fefe0c340946d0"
      "685d3c03b767f77d24cfd43443361b4cfad19a53ef4a4a3f9296ec47"
      "729fe10bafc967ee7f94c267f04082475ddd8410a44b153429f7205cbc6ec37b776e1e63"
      "c413fd368329df9705f95a891825f619bcb17752dcc6750552611b44",
      "af2c0e01f02ea89e16012e518d6b527461d8995219fb4433d26e124ed8405185f385a672"
      "250db4c2bfef9fe5a7f5efc11fd693f4d3fdf722ff75f37b0465c5f7"
      "e3b8fc244b3e63ff8b2fab39ecdabc749a27f917f2386476e1f9ab9dc1cedeee348f5a0a"
      "4f5a1e684e9cd5fdad39e7ff957e2e3bdfa76bf299fb5fa7f019bc51",
      "ff3b3ae93220fc4878c0ace1aeece6f967295b7ddc6f5e7ecc92cfd8b2eb23bb78b9d9d9"
      "38af77b7ec77943887ce857ad62b2d8f3e2e3acff539f7af25f046a5"
      "78b23e9e5329845ec75a08d61621569a44634a9492708a9f4e57c3c9959cf2d1b7e1fc4a"
      "5c147e405c5d1bfff90869f93375bc5fb08ec7297518dca46799ecac",
      "28b9bea64c598e245c7584f46fae3edb297c066f54aa0bbe67d4323c6959f49ad9e9c9f6"
      "e76f99ea33c2972c53bed8965d9f0f88e3f489f746b6ab3ad878bb15"
      "e60b42166fbe3eff02b36107d3",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4376U, &nameCaptureInfo);
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
  emlrtSetField(xEntryPoints, 0, "ResolvedFilePath",
                emlrtMxCreateString(
                    "C:\\Users\\SeokHoLee\\Desktop\\Git\\Project_GH\\matlab_"
                    "analysis\\02_scripts\\predict_exercise_index.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739895.69894675922));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2973910 (R2025a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("YYeDRTd7OjkFaiJ1UcAbxF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_predict_exercise_index_info.c) */
