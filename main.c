#include <stdio.h>
#include <string.h>
#include "calculator.h"

int main(int argc, char *argv[])
{
    if (argc == 4)
        return two_element_op_handler(argv);
    else if (argc == 3)
        return one_element_op_handler(argv);
    else if (argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0))
    {
        usage(argv[0]);
        return 0;
    }
    else
    {
        printf("%s%s%s%s%s\n", RED, "Invalid arguments!", GREEN, " Use --help or -h to see usage.", RESET_COLOR);
        return 1;
    }
}
