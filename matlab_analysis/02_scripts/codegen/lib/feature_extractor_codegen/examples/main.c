/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "feature_extractor_codegen.h"
#include "feature_extractor_codegen_initialize.h"
#include "feature_extractor_codegen_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_d150x6_real_T(double result_data[], int result_size[2]);

static double argInit_real_T(void);

/* Function Definitions */
static void argInit_d150x6_real_T(double result_data[], int result_size[2])
{
  int i;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result_size[0] = 2;
  result_size[1] = 6;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 12; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[i] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  feature_extractor_codegen_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_feature_extractor_codegen();
  /* Terminate the application.
You do not need to do this more than one time. */
  feature_extractor_codegen_terminate();
  return 0;
}

void main_feature_extractor_codegen(void)
{
  double raw_data_data[900];
  double features[32];
  int raw_data_size[2];
  /* Initialize function 'feature_extractor_codegen' input arguments. */
  /* Initialize function input argument 'raw_data'. */
  argInit_d150x6_real_T(raw_data_data, raw_data_size);
  /* Call the entry-point 'feature_extractor_codegen'. */
  feature_extractor_codegen(raw_data_data, raw_data_size, argInit_real_T(),
                            features);
}

/* End of code generation (main.c) */
