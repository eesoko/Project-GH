//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// FFTImplementationCallback.h
//
// Code generation for function 'FFTImplementationCallback'
//

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace internal {
namespace fft {
class FFTImplementationCallback {
public:
  static void dobluesteinfft(const array<double, 1U> &x, int n2blue, int nfft,
                             const array<double, 2U> &costab,
                             const array<double, 2U> &sintab,
                             const array<double, 2U> &sintabinv,
                             array<creal_T, 1U> &y);
  static void doHalfLengthRadix2(const array<double, 1U> &x,
                                 array<creal_T, 1U> &y, int unsigned_nRows,
                                 const array<double, 2U> &costab,
                                 const array<double, 2U> &sintab);

protected:
  static void r2br_r2dit_trig_impl(const array<creal_T, 1U> &x,
                                   int unsigned_nRows,
                                   const array<double, 2U> &costab,
                                   const array<double, 2U> &sintab,
                                   array<creal_T, 1U> &y);
  static void doHalfLengthBluestein(
      const array<double, 1U> &x, array<creal_T, 1U> &y, int nrowsx, int nRows,
      int nfft, const array<creal_T, 1U> &wwc, const array<double, 2U> &costab,
      const array<double, 2U> &sintab, const array<double, 2U> &costabinv,
      const array<double, 2U> &sintabinv);
};

} // namespace fft
} // namespace internal
} // namespace coder

#endif
// End of code generation (FFTImplementationCallback.h)
