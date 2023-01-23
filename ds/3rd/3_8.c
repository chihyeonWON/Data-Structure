#include <stdio.h>

char *pa[] = {
    "에러 1",
    "에러 2",
    "에러 3",
    "에러 4",
    "에러 5",
    "에러 6"};
void error(int err_num)
{
    printf(pa[err_num]);
}

int main()
{
    error(1);
}