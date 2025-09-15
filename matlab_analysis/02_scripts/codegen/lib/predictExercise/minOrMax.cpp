//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// minOrMax.cpp
//
// Code generation for function 'minOrMax'
//

// Include files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
double maximum(const array<double, 1U> &x)
{
  double ex;
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(0) - 1];
      if ((!(x[0] < ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
        ex = x[0];
      }
    }
  } else {
    int idx;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      int k;
      bool exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (int b_k{idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

double maximum(const array<double, 1U> &x, int &idx)
{
  double ex;
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
      idx = 1;
    } else {
      ex = x[x.size(0) - 1];
      if ((x[0] < ex) || (std::isnan(x[0]) && (!std::isnan(ex)))) {
        idx = x.size(0);
      } else {
        ex = x[0];
        idx = 1;
      }
    }
  } else {
    int b_idx;
    if (!std::isnan(x[0])) {
      b_idx = 1;
    } else {
      int k;
      bool exitg1;
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (b_idx == 0) {
      ex = x[0];
      idx = 1;
    } else {
      ex = x[b_idx - 1];
      idx = b_idx;
      b_idx++;
      for (int b_k{b_idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex < d) {
          ex = d;
          idx = b_k;
        }
      }
    }
  }
  return ex;
}

double minimum(const array<double, 1U> &x)
{
  double ex;
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(0) - 1];
      if ((!(x[0] > ex)) && ((!std::isnan(x[0])) || std::isnan(ex))) {
        ex = x[0];
      }
    }
  } else {
    int idx;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      int k;
      bool exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (int b_k{idx}; b_k <= last; b_k++) {
        double d;
        d = x[b_k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

} // namespace internal
} // namespace coder

// End of code generation (minOrMax.cpp)
