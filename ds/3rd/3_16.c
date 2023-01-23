
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct test
{
    int data;
    struct test *link;
} test_str;

void main()
{
    int i;
    test_str *ptest;

    ptest = (double *)malloc(sizeof(test_str));
    i = _msize(ptest);
    printf("ptest의 메모리의 크기는 %d", i);
    free(ptest);
}