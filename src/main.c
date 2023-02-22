#include "include/fur.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("fur: no input files\n");
        return 1;
    }
    fur_compile_file(argv[1]);

    return 0;
}