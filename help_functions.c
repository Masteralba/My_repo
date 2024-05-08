#include <stdio.h>

void error(const char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(0);
}