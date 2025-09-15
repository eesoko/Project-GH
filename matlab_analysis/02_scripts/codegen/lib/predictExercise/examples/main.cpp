//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// main.cpp
//
// Code generation for function 'main'
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
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

// Include files
#include "main.h"
#include "categorical.h"
#include "predictExercise.h"
#include "predictExercise_initialize.h"
#include "predictExercise_terminate.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static coder::array<double, 2U> argInit_Unboundedx6_real_T();

static double argInit_real_T();

// Function Definitions
static coder::array<double, 2U> argInit_Unboundedx6_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 6);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < 6; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_real_T();
    }
  }
  return result;
}

static double argInit_real_T()
{
  return 0.0;
}

int main(int, char **)
{
  // Initialize the application.
  // You do not need to do this more than one time.
  predictExercise_initialize();
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_predictExercise();
  // Terminate the application.
  // You do not need to do this more than one time.
  predictExercise_terminate();
  return 0;
}

void main_predictExercise()
{
  coder::categorical predictedExercise;
  coder::array<double, 2U> sensorData;
  // Initialize function 'predictExercise' input arguments.
  // Initialize function input argument 'sensorData'.
  sensorData = argInit_Unboundedx6_real_T();
  // Call the entry-point 'predictExercise'.
  predictExercise(sensorData, &predictedExercise);
}

// End of code generation (main.cpp)
