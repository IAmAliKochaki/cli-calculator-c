#ifndef CALCULATOR_H
#define CALCULATOR_H

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET_COLOR "\033[0m"

void usage(char *program_name);
int two_element_op_handler(char *argv[]);
int parser_double(const char *input, double *out);
void to_lower_string(char *str);

#endif // CALCULATOR_H
