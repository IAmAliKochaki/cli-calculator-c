#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "math_functions.h"
#include "calculator.h"


int two_element_op_handler(char *argv[])
{
  double first_number, second_number;
  if (!parser_double(argv[1], &first_number) || !parser_double(argv[3], &second_number))
    return 1;

  to_lower_string(argv[2]);
  if (argv[2][1] != '\0' && strcmp(argv[2], "min") != 0 && strcmp(argv[2], "max") != 0)
  {
    printf("%s%s%s\n", RED, "Invalid operation!", RESET_COLOR);
    return 1;
  }

  double (*operation)(double, double) = NULL;
  if (strlen(argv[2]) == 1)
  {
    char op = argv[2][0];
    switch (op)
    {
    case '+':
      operation = ADD;
      break;
    case '-':
      operation = SUB;
      break;
    case 'x':
      operation = MUL;
      break;
    case '/':
      operation = DIV;
      break;
    case '^':
      operation = POW;
      break;
    default:
      printf("%s%s%s\n", RED, "Invalid operation!", RESET_COLOR);
      return 1;
    }
  }
  else
  {
    if (strcmp(argv[2], "min") == 0)
      operation = MIN;
    else if (strcmp(argv[2], "max") == 0)
      operation = MAX;
    else
    {
      printf("%s%s%s\n", RED, "Invalid operation!", RESET_COLOR);
      return 1;
    }
  }

  double result = operation(first_number, second_number);
  if (!isnan(result))
  {
    printf("%s%s%s%g\n", GREEN, "Result: ", RESET_COLOR, result);
    return 0;
  }
  else
    return 1;
}

int one_element_op_handler(char *argv[])
{
  double number;
  if (!parser_double(argv[2], &number))
    return 1;

  double (*operation)(double) = NULL;

  char *op = argv[1];
  to_lower_string(op);
  if (strcmp(op, "sin") == 0)
    operation = SIN;
  else if (strcmp(op, "cos") == 0)
    operation = COS;
  else if (strcmp(op, "tan") == 0)
    operation = TAN;
  else if (strcmp(op, "cot") == 0)
    operation = COT;
  else if (strcmp(op, "fact") == 0)
    operation = FACTORIAL;
  else
  {
    printf("%s%s%s\n", RED, "Invalid operation!", RESET_COLOR);
    return 1;
  }

  double result = operation(number);
  if (!isnan(result))
  {
    printf("%s%s%s%g\n", GREEN, "Result: ", RESET_COLOR, result);
    return 0;
  }
  else
    return 1;
}

int parser_double(const char *input, double *out)
{
  char *endptr;
  errno = 0;
  double value = strtod(input, &endptr);

  if (errno == ERANGE)
  {
    printf("%s%s%s\n", RED, "The number is too large or too small(out of range)", RESET_COLOR);
    return 0;
  }

  if (endptr == input || *endptr != '\0')
  {
    printf("%s%s%s\n", RED, "Invalid number", RESET_COLOR);
    return 0;
  }

  *out = value;
  return 1;
}

void to_lower_string(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = tolower((unsigned char)str[i]);
}

void usage(char *program_name)
{
  printf("%s%s%s\n", GREEN, "Usage:", RESET_COLOR);
  printf("\t%s\n", "1:first_number operator second_number");
  printf("\t%s\n", "2:operator number");
  
  printf("%s%s%s\n", GREEN, "Example:", RESET_COLOR);
  printf("\t%s\n", "calc 3.5 x 2.1");
  printf("\t%s\n", "calc fact 5");
  
  printf("%s%s%s\n", GREEN, "Operators:", RESET_COLOR);
  printf("\t%s\n", "+ --> add");
  printf("\t%s\n", "- --> subtract");
  printf("\t%s\n", "x --> multiply");
  printf("\t%s\n", "/ --> division");
  printf("\t%s\n", "^ --> power");
  printf("\t%s\n", "min --> min");
  printf("\t%s\n", "max --> max");
  printf("\t%s\n", "sin --> sin");
  printf("\t%s\n", "cos --> cos");
  printf("\t%s\n", "tan --> tan");
  printf("\t%s\n", "cot --> cot");
  printf("\t%s\n", "fact --> factorial");

  printf("%s%s%s\n", GREEN, "--help/-h --> usage", RESET_COLOR);
}
