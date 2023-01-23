#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main()
{
    int i, *pi;
    pi = (int *)malloc(100 * sizeof(char));
    i = _msize(pi);
    printf("pi 메모리의 크기는 %d", i);
    printf("%d", *pi);
    free(pi);
}