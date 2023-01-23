#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand();
        printf("a[%d]:%d\n", i, a[i]);
    }
    int max;
    int min;
    max = min = a[0];
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    printf("max:%d,min:%d", max, min);
}