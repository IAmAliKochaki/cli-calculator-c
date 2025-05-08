#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "math_functions.h"

#define RED "\033[31m"
#define RESET_COLOR "\033[0m"

double ADD(double a, double b)
{
  return a + b;
}

double SUB(double a, double b)
{
  return a - b;
}

double MUL(double a, double b)
{
  return a * b;
}

double DIV(double a, double b)
{
  if (b == 0)
  {
    printf("%s%s%s\n", RED, "Error: The second value of division cannot be zero!", RESET_COLOR);
    return NAN;
  }
  return a / b;
}

double POW(double a, double b)
{
  return pow(a, b);
}

double MIN(double a, double b)
{
  return a < b ? a : b;
}

double MAX(double a, double b)
{
  return a > b ? a : b;
}

double SIN(double a)
{
  return sin(a);
}
double COS(double a)
{
  return cos(a);
}
double TAN(double a)
{
  if (cos(a) == 0) {
    printf("%stan(%.4f) is undefined because cos(%.4f) is zero%s\n", RED, a, a, RESET_COLOR);
    return NAN;
  }
  return tan(a);
}
double COT(double a)
{
  
  if (sin(a) == 0) {
    printf("%stan(%.4f) is undefined because sin(%.4f) is zero%s\n", RED, a, a, RESET_COLOR);
    return NAN;
  }
  return 1 / tan(a);
}
double FACTORIAL(double a)
{
  if (a < 0) {
    printf("%sFactorial number must be >= 0%s\n", RED, RESET_COLOR);
    return NAN;
  }
  int int_input = (int)a;
  int result = 1;
  for (int i = 2; i <= int_input; i++)
    result *= i;
  return result;
}
