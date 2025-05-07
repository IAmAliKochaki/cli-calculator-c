#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "math_functions.h"
#include "calculator.h"

void usage(char *program_name)
{
  printf("%sUsage:%s %s first_number operator second_number\n", RED, program_name, GREEN);
  printf("Example: calc 3.5 x 2.1%s\n", RESET_COLOR);
  printf("Operators:\n");
  printf(" + --> add\n");
  printf(" - --> subtract\n");
  printf(" x --> multiply\n");
  printf(" / --> division\n");
  printf(" ^ --> power\n");
}

int two_element_op_handler(char *argv[])
{
  double first_number, second_number;
  if (!parser_double(argv[1], &first_number) || !parser_double(argv[3], &second_number))
    return 1;
  char op = argv[2][0];
  if (argv[2][1] != '\0')
  {
    printf("%s%s%s\n", RED, "Invalid operation!", RESET_COLOR);
    usage(argv[0]);
    return 1;
  }
  double (*operation)(double, double) = NULL;
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
    usage(argv[0]);
    return 1;
  }
  double result = operation(first_number, second_number);
  if (!isnan(result))
  {
    printf("%s%s%s%g\n", GREEN, "Result: ", RESET_COLOR, result);
    return 0;
  }
  else
  {
    return 1;
  }
}

int parser_double(const char *input, double *out)
{
  char *endptr;
  errno = 0;
  double value = strtod(input, &endptr);

  if (errno == ERANGE)
  {
    printf("%s%s%s\n", RED, "The number is too lager or too small(out of range)", RESET_COLOR);
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
