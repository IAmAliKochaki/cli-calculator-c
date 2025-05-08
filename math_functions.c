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
