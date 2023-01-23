#include <stdio.h>
#define LIST_SIZE 10

int list[LIST_SIZE] = {23, 45, 12, 34, 65, 25, 89, 61, 26, 11};

main()
{
    int i;
    for (i = 0; i < LIST_SIZE; i++)
    {
        printf("list[%d]의 주소 = %p\n", i, &list[i]);
    }
}