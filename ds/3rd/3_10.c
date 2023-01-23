#include <stdio.h>
#include <stdlib.h> // malloc 함수와 free함수가 들어있는 stdlib.h
#include <memory.h>

void main()
{
    char *pc;

    pc = (char *)malloc(1);
    *pc = 100;
    printf("c = %d\n", *pc);
    free(pc);
}