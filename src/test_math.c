#include <check.h>
#include <math.h>

#include "my_math.h"

START_TEST(abs_test_1) {
  ck_assert_double_eq(abs(-7), my_abs(-7));
  ck_assert_double_eq(abs(-98), my_abs(-98));
  ck_assert_double_eq(abs(123), my_abs(123));
  ck_assert_double_eq(abs(10009), my_abs(10009));
  ck_assert_double_eq(abs(-10009), my_abs(-10009));
}
END_TEST

START_TEST(abs_test_2) {
  ck_assert_int_eq(my_abs(-10), abs(-10));
  ck_assert_int_eq(my_abs(-0), abs(-0));
}
END_TEST

START_TEST(acos_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = my_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(acos_test_2) {
  for (float k = -1; k <= 1; k += 0.0305) {
    double a = my_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(acos_test_3) {
  double a = my_acos(1);
  double b = acos(1);
  ck_assert_double_eq_tol(a, b, 1e-6);
}
END_TEST

START_TEST(asin_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = my_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
  ck_assert_double_eq_tol(asin(1), my_asin(1), 1e-6);
}
END_TEST

START_TEST(asin_test_2) {
  for (float k = -1; k <= 1; k += 0.0771) {
    double a = my_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(atan_test_1) {
  for (float k = -10; k <= 10; k += 4) {
    double a = my_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(atan_test_2) {
  double a = 12;
  ck_assert_double_eq_tol(atan(a), my_atan(a), 1e-6);
  a = 0.4;
  ck_assert_double_eq_tol(atan(a), my_atan(a), 1e-6);
  a = -0.333;
  ck_assert_double_eq_tol(atan(a), my_atan(a), 1e-6);
  a = 13.54;
  ck_assert_double_eq_tol(atan(a), my_atan(a), 1e-6);
  a = MY_EXP;
  ck_assert_double_eq_tol(atan(a), my_atan(a), 1e-6);
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_double_eq(ceil(INFINITY), my_ceil(MY_INF));
  ck_assert_double_eq(ceil(-INFINITY), my_ceil(-MY_INF));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(my_ceil(MY_NAN));
  ck_assert_double_eq(ceil(-7.0), my_ceil(-7.0));
  ck_assert_double_eq(ceil(-98.1), my_ceil(-98.1));
  ck_assert_double_eq(ceil(123.02), my_ceil(123.02));
  ck_assert_double_eq(ceil(10009.00123), my_ceil(10009.00123));
  ck_assert_double_eq(ceil(-10009.555), my_ceil(-10009.555));
  ck_assert_double_eq(ceil(-0.10009), my_ceil(-0.10009));
  ck_assert_double_eq(ceil(-1e-23), my_ceil(-1e-23));
}
END_TEST

START_TEST(cos_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * MY_PI; k > -2 * MY_PI; k -= MY_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * MY_PI), my_cos(k + R * MY_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(cos_test_2) {
  ck_assert_ldouble_nan(my_cos(MY_INF));
  ck_assert_ldouble_nan(my_cos(-MY_INF));
  ck_assert_ldouble_nan(my_cos(MY_NAN));
  ck_assert_ldouble_nan(my_cos(-MY_NAN));
  ck_assert_ldouble_eq_tol(my_cos(0.5), cos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-0.5), cos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(1.1), cos(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-2.1), cos(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-0), cos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(5.123456789123), cos(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(0.00000004564897), cos(0.00000004564897),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_cos(17431.123), cos(17431.123), 1e-6);
}
END_TEST

START_TEST(exp_test_1) {
  for (double k = -21; k < 21; k += 1) {
    double a = my_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_2) {
  for (double k = -15; k < 15; k += 0.123) {
    double a = my_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_3) {
  for (double k = -5; k < 5; k += 0.00573) {
    double a = my_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_4) {
  ck_assert_double_nan(my_exp(MY_NAN));
  ck_assert_double_eq(exp(INFINITY), my_exp(MY_INF));
  ck_assert_double_eq(exp(-INFINITY), my_exp(-MY_INF));
  ck_assert_double_eq(exp(0), my_exp(0));
  ck_assert_double_eq(exp(1), my_exp(1));
  ck_assert_double_eq(exp(710), my_exp(710));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq(fabs(INFINITY), my_fabs(MY_INF));
  ck_assert_double_eq(fabs(-INFINITY), my_fabs(-MY_INF));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(my_fabs(MY_NAN));
  ck_assert_double_eq(fabs(-7.0), my_fabs(-7.0));
  ck_assert_double_eq(fabs(-98.1), my_fabs(-98.1));
  ck_assert_double_eq(fabs(123.02), my_fabs(123.02));
  ck_assert_double_eq(fabs(10009.0), my_fabs(10009.0));
  ck_assert_double_eq(fabs(-10009.555), my_fabs(-10009.555));
  ck_assert_double_eq(fabs(-0.10009), my_fabs(-0.10009));
  ck_assert_double_eq(fabs(-1e23), my_fabs(-1e23));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq(floor(INFINITY), my_floor(MY_INF));
  ck_assert_double_eq(floor(-INFINITY), my_floor(-MY_INF));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(my_floor(MY_NAN));
  ck_assert_double_eq(floor(-7.0), my_floor(-7.0));
  ck_assert_double_eq(floor(-98.1), my_floor(-98.1));
  ck_assert_double_eq(floor(123.02), my_floor(123.02));
  ck_assert_double_eq(floor(10009.00123), my_floor(10009.00123));
  ck_assert_double_eq(floor(-10009.555), my_floor(-10009.555));
  ck_assert_double_eq(floor(-0.10009), my_floor(-0.10009));
  ck_assert_double_eq(floor(-1e-23), my_floor(-1e-23));
  ck_assert_double_eq(floor(100091234.5), my_floor(100091234.5));
}
END_TEST

START_TEST(fmod_test_1) {
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(my_fmod(1, 0));
  ck_assert_double_eq(fmod(0, -1), my_fmod(0, -1));
  ck_assert_double_eq(fmod(0, 1), my_fmod(0, 1));
  ck_assert_double_nan(fmod(INFINITY, -1));
  ck_assert_double_nan(my_fmod(INFINITY, -1));
  ck_assert_double_eq(fmod(-1, -INFINITY), my_fmod(-1, -MY_INF));
  ck_assert_double_eq(fmod(0, INFINITY), my_fmod(0, MY_INF));
  ck_assert_double_nan(my_fmod(0, MY_NAN));
  ck_assert_double_nan(fmod(0, NAN));
  ck_assert_double_nan(my_fmod(MY_NAN, MY_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(my_fmod(MY_NAN, MY_INF));
  ck_assert_double_nan(my_fmod(MY_INF, MY_NAN));
  ck_assert_double_nan(my_fmod(MY_NAN, -MY_INF));
  ck_assert_double_nan(my_fmod(-MY_INF, MY_NAN));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(fmod_test_2) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), my_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), my_fmod(b, a));
    }
  }
}
END_TEST

START_TEST(log_test_1) {
  for (double k = 1; k < 100; k += 13.2) {
    double a = my_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_2) {
  for (double k = 0.1; k < 4; k += 0.24) {
    double a = my_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_3) {
  for (double k = 0.1; k < 10000; k += 123) {
    double a = my_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_4) {
  for (double k = 0.05; k < 10; k *= 5) {
    double a = my_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_5) {
  ck_assert_double_nan(my_log(MY_NAN));
  ck_assert_double_eq(log(0), my_log(0));
  ck_assert_double_nan(my_log(-3));
  ck_assert_double_nan(my_log(-MY_INF));
  ck_assert_double_eq(log(M_E), my_log(MY_EXP));
  ck_assert_double_eq_tol(log(2), my_log(2), 1e-6);
}
END_TEST

START_TEST(pow_test_1) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1) {
      long double a = my_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
      a = my_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_2) {
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = my_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
      a = my_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_3) {
  ck_assert_double_eq(pow(1, 0), my_pow(1, 0));
  ck_assert_double_eq(pow(0, 0), my_pow(0, 0));
  ck_assert_double_eq(pow(0, -1), my_pow(0, -1));
  ck_assert_double_eq(pow(0, 1), my_pow(0, 1));
  ck_assert_double_eq(pow(INFINITY, 0), my_pow(MY_INF, 0));
  ck_assert_double_eq(pow(INFINITY, -1), my_pow(MY_INF, -1));
  ck_assert_double_eq(pow(0, INFINITY), my_pow(0, MY_INF));
  ck_assert_double_nan(my_pow(0, MY_NAN));
  ck_assert_double_nan(my_pow(MY_NAN, MY_NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY), my_pow(MY_INF, MY_INF));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), my_pow(MY_INF, -MY_INF));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY), my_pow(-MY_INF, -MY_INF));
  ck_assert_double_nan(my_pow(MY_NAN, MY_INF));
  ck_assert_double_nan(my_pow(MY_NAN, -MY_INF));
  ck_assert_double_eq(pow(2, INFINITY), my_pow(2, MY_INF));
  ck_assert_double_eq(pow(0.5, INFINITY), my_pow(0.5, MY_INF));
  ck_assert_double_eq(pow(2, -INFINITY), my_pow(2, -MY_INF));
  ck_assert_double_eq(pow(0.5, -INFINITY), my_pow(0.5, -MY_INF));
  ck_assert_double_eq(pow(-2, -INFINITY), my_pow(-2, -MY_INF));
  ck_assert_double_eq(pow(0.0, INFINITY), my_pow(0.0, MY_INF));
  ck_assert_double_eq(pow(0.0, -INFINITY), my_pow(0.0, -MY_INF));
  ck_assert_double_eq(pow(INFINITY, 5), my_pow(MY_INF, 5));
  ck_assert_double_eq(pow(-1.0, -INFINITY), my_pow(-1.0, -MY_INF));
  ck_assert_double_eq(pow(-INFINITY, 0), my_pow(-MY_INF, 0));
  ck_assert_double_eq(pow(-INFINITY, 7), my_pow(-MY_INF, 7));
  ck_assert_double_eq(pow(-INFINITY, INFINITY), my_pow(-MY_INF, MY_INF));
}
END_TEST

START_TEST(sin_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * MY_PI; k > -2 * MY_PI; k -= MY_PI / 17) {
      ck_assert_double_eq_tol(sin(k + R * MY_PI), my_sin(k + R * MY_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(sin_test_2) {
  ck_assert_ldouble_nan(my_sin(MY_INF));
  ck_assert_ldouble_nan(my_sin(-MY_INF));
  ck_assert_ldouble_nan(my_sin(MY_NAN));
  ck_assert_ldouble_nan(my_sin(-MY_NAN));
  ck_assert_ldouble_eq_tol(my_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-0.5), sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(1.1), sin(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-2.1), sin(-2.1), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-0), sin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(5.123456789123), sin(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(0.00000004564897), sin(0.00000004564897),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_sin(1234.188), sin(1234.188), 1e-6);
}
END_TEST

START_TEST(sqrt_test_1) {
  for (double k = 0; k < 21; k += 3) {
    double a = my_sqrt(k);
    double b = sqrt(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(sqrt_test_2) {
  ck_assert_double_nan(my_sqrt(MY_NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_eq(my_sqrt(MY_INF), sqrt(INFINITY));
  ck_assert_double_nan(my_sqrt(-MY_INF));
  ck_assert_double_nan(sqrt(-INFINITY));
  ck_assert_double_nan(my_sqrt(-5));
  ck_assert_double_nan(sqrt(-5));
  ck_assert_double_eq_tol(my_sqrt(1000), sqrt(1000), 1e-6);
}
END_TEST

START_TEST(tan_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * MY_PI; k > -2 * MY_PI; k -= MY_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * MY_PI), my_tan(k + R * MY_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(tan_test_2) {
  ck_assert_ldouble_nan(my_cos(MY_INF));
  ck_assert_ldouble_nan(my_cos(-MY_INF));
  ck_assert_ldouble_nan(my_cos(MY_NAN));
  ck_assert_ldouble_nan(my_cos(-MY_NAN));
  ck_assert_ldouble_eq_tol(my_tan(0.5), tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-0.5), tan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(1.1), tan(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(my_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-0), tan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(0.00000004564897), tan(0.00000004564897),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_tan(1234.188), tan(1234.188), 1e-6);
}
END_TEST

START_TEST(sin_cos_tan_test) {
  ck_assert_double_nan(my_sin(MY_NAN));
  ck_assert_double_nan(my_cos(MY_NAN));
  ck_assert_double_nan(my_tan(MY_NAN));
  ck_assert_double_nan(my_sin(MY_INF));
  ck_assert_double_nan(my_cos(MY_INF));
  ck_assert_double_nan(my_tan(MY_INF));
  ck_assert_double_nan(my_sin(-MY_INF));
  ck_assert_double_nan(my_cos(-MY_INF));
  ck_assert_double_nan(my_tan(-MY_INF));
}
END_TEST

START_TEST(asin_acos_atan_test) {
  ck_assert_double_nan(my_asin(MY_NAN));
  ck_assert_double_nan(my_acos(MY_NAN));
  ck_assert_double_nan(my_atan(MY_NAN));
  ck_assert_double_nan(my_asin(MY_INF));
  ck_assert_double_nan(my_acos(MY_INF));
  ck_assert_double_nan(my_asin(-MY_INF));
  ck_assert_double_nan(my_acos(-MY_INF));
  ck_assert_double_eq(atan(-INFINITY), atan(-MY_INF));
  ck_assert_double_nan(my_asin(5));
  ck_assert_double_nan(my_acos(6));
  ck_assert_double_nan(my_asin(-8));
}
END_TEST

Suite *my_math_suite(void) {
  Suite *suite;

  suite = suite_create("my_math");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, abs_test_1);
  tcase_add_test(tcase_core, abs_test_2);
  tcase_add_test(tcase_core, acos_test_1);
  tcase_add_test(tcase_core, acos_test_2);
  tcase_add_test(tcase_core, acos_test_3);
  tcase_add_test(tcase_core, asin_test_1);
  tcase_add_test(tcase_core, asin_test_2);
  tcase_add_test(tcase_core, atan_test_1);
  tcase_add_test(tcase_core, atan_test_2);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, cos_test_1);
  tcase_add_test(tcase_core, cos_test_2);
  tcase_add_test(tcase_core, exp_test_1);
  tcase_add_test(tcase_core, exp_test_2);
  tcase_add_test(tcase_core, exp_test_3);
  tcase_add_test(tcase_core, exp_test_4);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, fmod_test_1);
  tcase_add_test(tcase_core, fmod_test_2);
  tcase_add_test(tcase_core, log_test_1);
  tcase_add_test(tcase_core, log_test_2);
  tcase_add_test(tcase_core, log_test_3);
  tcase_add_test(tcase_core, log_test_4);
  tcase_add_test(tcase_core, log_test_5);
  tcase_add_test(tcase_core, pow_test_1);
  tcase_add_test(tcase_core, pow_test_2);
  tcase_add_test(tcase_core, pow_test_3);
  tcase_add_test(tcase_core, sin_test_1);
  tcase_add_test(tcase_core, sin_test_2);
  tcase_add_test(tcase_core, sqrt_test_1);
  tcase_add_test(tcase_core, sqrt_test_2);
  tcase_add_test(tcase_core, tan_test_1);
  tcase_add_test(tcase_core, tan_test_2);
  tcase_add_test(tcase_core, sin_cos_tan_test);
  tcase_add_test(tcase_core, asin_acos_atan_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = my_math_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);

  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
