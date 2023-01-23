#include <stdio.h>

void main()
{
    char *pc;
    int *pi;
    float *pf;
    double *pd;

    char c;
    int i;
    float f;
    double d;

    pc = NULL;
    *pc = 100;
    printf("pc = %lu\n", pc);
}