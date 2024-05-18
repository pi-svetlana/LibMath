#include "my_math.h"

int my_abs(int x) { return (x < 0 ? -x : x); }

long double my_acos(double x) {
  long double result;
  if (x == 1)
    result = 0;
  else if (x == -1)
    result = MY_PI;
  else if (x < 1 && x >= 0)
    result = my_atan(my_sqrt(1 - x * x) / x);
  else if (x < 0 && x > -1)
    result = MY_PI + my_atan(my_sqrt(1 - x * x) / x);
  else
    result = MY_NAN;
  return result;
}

long double my_asin(double x) {
  long double result;
  if (x > 1 || x < -1)
    result = MY_NAN;
  else if (x == 1 || x == -1)
    result = MY_PI / (2 * x);
  else if (x > -1 && x < 1)
    result = MY_PI / 2 - my_acos(x);
  else
    result = MY_NAN;
  return result;
}

long double my_atan(double x) {
  long double result = 0;
  long double t = x;
  if (x == MY_INF)
    result = MY_PI / 2;
  else if (x == -MY_INF)
    result = -MY_PI / 2;
  else if (x == 0)
    return x;
  else if (x == 1)
    result = MY_PI / 4;
  else if (x == -1)
    result = -MY_PI / 4;
  else if (my_fabs(x) < 1) {
    for (int n = 1; my_fabs(t / n) > MY_EPS; n += 2) {
      result += t / n;
      t = -t * x * x;
    }
  } else {
    for (int n = 1; my_fabs(1 / t / n) > MY_EPS; n += 2) {
      result += 1 / t / n;
      t = -t * x * x;
    }
    result = (MY_PI * my_fabs(x) / (2 * x)) - result;
  }
  return result;
}

long double my_ceil(double x) {
  long double result;
  if (!is_finite(x)) {
    result = x;
  } else {
    result = (long long int)x;
    if (x > 0 && result != x) {
      result += 1;
    }
  }
  return result;
}

long double my_cos(double x) {
  long double result = 0;
  if (is_nan(x) || x == MY_INF || x == -MY_INF) {
    result = MY_NAN;
  } else if (x == 0) {
    result = 1;
  } else {
    int sign = 1;
    x = my_fmod(my_fabs(x), 2 * MY_PI);
    if (x > 3 * MY_PI / 2) {
      x -= MY_PI;
      sign *= -1;
    }
    if (x > MY_PI / 2) {
      x = MY_PI - x;
      sign *= -1;
    }
    double t = 1, s = 1;
    for (int n = 2; my_fabs(t) > MY_EPS; n += 2) {
      s += t = -t * x * x / n / (n - 1);
    }
    result = s * sign;
    if (my_fabs(s) < MY_EPS) {
      result = 0;
    }
  }
  return result;
}

long double my_exp(double x) {
  long double result = 0;
  if (!is_finite(x)) {
    if (is_nan(x) || x == MY_INF) {
      result = x;
    } else if (x == -MY_INF) {
      result = 0;
    } else {
      result = x;
    }
  } else if (x == 1) {
    result = MY_EXP;
  } else {
    double t = 1;
    int check = 1;
    result = 1;
    for (int n = 1; my_fabs(t) > MY_EPS && check; n++) {
      result += t *= my_fabs(x) / n;
      if (result > MY_DBL_MAX) {
        result = MY_INF;
        check = 0;
      }
      if (result < MY_EPS) {
        result = 0;
        check = 0;
      }
    }
    if (x < 0) {
      result = 1 / result;
    }
  }
  return result;
}

long double my_fabs(double x) {
  long double result;
  if (!is_finite(x)) {
    if (is_nan(x) || x == MY_INF) {
      result = x;
    }
    if (x == -MY_INF) {
      result = MY_INF;
    }
  } else {
    result = x < 0 ? -x : x;
  }
  return result;
}

long double my_floor(double x) {
  long double result;
  if (!is_finite(x)) {
    result = x;
  } else {
    result = (long long int)x;
    if (x < 0 && result != x) {
      result -= 1;
    }
  }
  return result;
}

long double my_fmod(double x, double y) {
  long double result;

  if ((is_nan(x) || is_nan(y)) || x == MY_INF || x == -MY_INF || y == 0) {
    result = MY_NAN;
  } else if (x == 0 && !is_nan(y)) {
    result = 0;
  } else if ((x != MY_INF && x != -MY_INF) &&
             (y == MY_INF || y == -MY_INF)) {
    result = x;
  } else {
    long long int quot = x / y;
    result = x - quot * y;
  }
  return result;
}

long double my_log(double x) {
  long double result = 0;
  long double t;
  if (x < 0) {
    result = MY_NAN;
  } else if (!is_finite(x)) {
    result = x;
  } else if (x == 1) {
    result = 0;
  } else if (x == 0) {
    result = -MY_INF;
  } else if (x == MY_EXP) {
    result = 1;
  } else if (my_fabs(x) > 1) {
    double y = x / (x - 1);
    t = 1;
    for (double n = 1; my_fabs(t / n) > MY_EPS; n++) {
      t = t / y;
      result += t / n;
    }
  } else {
    t = x - 1;
    for (double n = 1; my_fabs(t / n) > MY_EPS; n++) {
      result += t / n;
      t = -t * (x - 1);
    }
  }
  return result;
}

long double my_pow(double base, double exp) {
  long double result = 0;
  double sign_zero = 1.0 / base;
  if (sign_zero == 1.0 / 0.0 && my_fmod(exp, 1) == 0 && exp != 0) {
    if (exp < 0) result = MY_INF;
    if (exp > 0) result = 0;
  } else if (sign_zero == -1.0 / 0.0 && my_fmod(exp, 1) == 0 && exp != 0) {
    if (exp < 0) {
      if (my_fmod(exp, 2) != 0)
        result = -MY_INF;
      else
        result = MY_INF;
    }
    if (exp > 0) {
      if (my_fmod(exp, 2) != 0)
        result = -0.0;
      else
        result = 0;
    }
  } else if (base == -1 && (exp == MY_INF || exp == -MY_INF)) {
    result = 1;
  } else if (base == 1 || exp == 0) {
    result = 1;
  } else if (base < 0 && is_finite(base) && is_finite(exp) &&
             my_fmod(exp, 1) != 0) {
    result = MY_NAN;
  } else if (my_fabs(base) > 1 && base != MY_INF && base != -MY_INF &&
             is_inf(exp)) {
    if (exp == -MY_INF) result = 0;
    if (exp == MY_INF) result = MY_INF;
  } else if (my_fabs(base) < 1 && base != 0 && is_inf(exp)) {
    if (exp == -MY_INF) result = MY_INF;
    if (exp == MY_INF) result = 0;
  } else if (base == -MY_INF) {
    if (exp < 0 && my_fmod(exp, 2) != 0) result = -0.0;
    if (exp < 0 && my_fmod(exp, 2) == 0) result = 0;
    if (exp > 0 && my_fmod(exp, 2) != 0) result = -MY_INF;
    if (exp > 0 && my_fmod(exp, 2) == 0) result = MY_INF;
    if (exp == -MY_INF) result = 0;
    if (exp == MY_INF) result = MY_INF;
  } else if (base == MY_INF) {
    if (exp < 0) result = 0;
    if (exp > 0) result = MY_INF;
  } else if (is_nan(base) || is_nan(exp)) {
    result = MY_NAN;
  } else if (exp == 1) {
    result = base;
  } else {
    int sign = base < 0 ? -1 : 1;
    result = my_exp(exp * my_log(base * sign));
    if (my_fmod(exp, 2)) result *= sign;
    if (result > MY_DBL_MAX) result = MY_INF;
  }
  return result;
}

long double my_sin(double x) {
  long double result;
  if (is_nan(x) || x == MY_INF || x == -MY_INF) {
    result = MY_NAN;
  }
  if (is_finite(x)) {
    int sign = (x < 0) ? -1 : 1;
    x = my_fmod(my_fabs(x), 2 * MY_PI);
    if (x > MY_PI) {
      x -= MY_PI;
      sign *= -1;
    }
    if (x > MY_PI / 2) {
      x = MY_PI - x;
    }
    double t = x, s = x;
    for (int n = 3; my_fabs(t) > MY_EPS; n += 2) {
      s += t = -t * x * x / n / (n - 1);
    }
    result = s * sign;
    if (my_fabs(s) < MY_EPS) {
      result = 0;
    }
  }
  return result;
}

long double my_sqrt(double x) {
  long double result;
  if (is_nan(x) || x == MY_INF || x == 0) {
    result = x;
  } else if (x < 0) {
    result = MY_NAN;
  } else {
    long double temp;
    result = x;
    do {
      temp = result;
      result = (temp + x / temp) / 2;
    } while (result != temp);
  }
  return result;
}

long double my_tan(double x) {
  long double result;
  if (!is_finite(x)) {
    result = MY_NAN;
  } else {
    result = my_sin(x) / my_cos(x);
  }
  return result;
}
