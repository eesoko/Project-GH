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
      "789cdd56cd8ed330107661415c80e5c213ac90105254955fed6de92e6d11db964d0b42f5"
      "aa7593d9ae5bc78e6c974ddf801be225e0ce0971e2013872e42d3823"
      "d12671d38da882b610b49dcb78f2d9fe66c69a4f4185da7e0121740dc576237257e37033"
      "f617d0694be385d85f4cc5c62ea18d53e70cfe36f68ee01a021d059c",
      "78303fe90a8f72c2756be20392a0047b0d6e881c51062dea81bd18d46791f764019a0733"
      "68b62e1f8333b2c71e92c72ac9902d06f37ef496d4bb91d18fb4a5fb"
      "91de67f88233f299fb6f66f019dc97e05247772100e950055dca5d0856afdbf05e5e9a47"
      "84b862dc6790f07d5991af978a516a9fc13b7b87e56ddc562015b641",
      "8caae21900de0535d2c2c715aa71538a214c3b53a9628f6846fa5dc2099b28aa70b1d455"
      "8ea4be56f8f7fdb3bcacfe5dffc37ad23ed97f25f45fef7f0fa1bcf8"
      "7e34aab7f3e433f6bff8f29ac3a1cd2b8322293e908d80d9a5bb073b939dbddd248f6606"
      "4f561e68499cd7fdbd25e7ff957eae3bdfa733f299fb5f64f019bcd3",
      "fe3b3ae930207c5fb8c0ace9aefce6f963255f7d7cdf7ff7214f3e63ebae8f957695350e"
      "0627c3e1e36a6370f25c14ebece11ae9e3aaf3dc5e72ff660aefd4ca"
      "875bd19c4a21f416d642b0be08b0d2241c53a2948401be93aca6932b39e5b36fd3f995b8"
      "2c3c9f38ba19fdf90869790b75bc59b18e5b197518dca46799ecac30",
      "b9b1a64c592d49b83a12d23bbffa6c67f019bc53abaff89e61cbf0bc65e16be6a727db9f"
      "bfe5aacf08ff64b9f2c5b6eefafc94b45a63e2be94fdbaf6efbd7a14"
      "144b4296cfbf3eff026f950741",
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
                emlrtMxCreateString("yMFsulTXnJmEcYysPzTJKF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_predict_exercise_index_info.c) */
