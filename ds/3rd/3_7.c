#include <stdio.h>

void main(void)
{
    char str[] = "What is Pointer?";
    char *p;
    int i;

    p = str;
    /* 널 문자가 발견될 때까지 반복한다. */
    for (i = 0; p[i] != NULL; i++)
        printf("%c", p[i]);
}