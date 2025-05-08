#include <stdio.h>
#include "calculator.h"

int main(int argc, char *argv[])
{
    if (argc == 4)
        return two_element_op_handler(argv);
    printf("%s%s%s\n", RED, "Invalid arguments!", RESET_COLOR);
    usage(argv[0]);
}
