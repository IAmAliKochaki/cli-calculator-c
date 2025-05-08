#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "math_functions.h"
#include "calculator.h"

void usage(char *program_name)
{
  printf("%sUsage:%s %s first_number operator second_number\n", RED, RESET_COLOR, program_name);
  printf("Example: calc 3.5 x 2.1%s\n", RESET_COLOR);
  printf("Operators:\n");
  printf(" + --> add\n");
  printf(" - --> subtract\n");
  printf(" x --> multiply\n");
  printf(" / --> division\n");
  printf(" ^ --> power\n");
  printf(" min --> min\n");
  printf(" max --> power\n");

  exit(1);
}

int two_element_op_handler(char *argv[])
{
  double first_number, second_number;
  if (!parser_double(argv[1], &first_number) || !parser_double(argv[3], &second_number))
    return 1;

  to_lower_string(argv[2]);
  if (argv[2][1] != '\0' && strcmp(argv[2], "min") != 0 && strcmp(argv[2], "max") != 0)
  {
    printf("%s%s%s\n", RED, "Invalid operation!", RESET_COLOR);
    usage(argv[0]);
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
      usage(argv[0]);
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
      usage(argv[0]);
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
