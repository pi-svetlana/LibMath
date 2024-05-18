#ifndef MY_MATH_H
#define MY_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define MY_PI 3.14159265358979323846264338327950288
#define MY_EXP 2.71828182845904523536028747135266250
#define MY_DBL_MIN -10e-307
#define MY_DBL_MAX 1.7976931348623158e+308
#define MY_EPS 2.220446049250e-16
#define MY_INF 1.0 / 0.0
#define MY_NAN 0.0 / 0.0

#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define is_finite(x) __builtin_isfinite(x)

int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double base, double exp);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);

#endif
