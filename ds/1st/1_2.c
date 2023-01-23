#include <stdio.h>

void matrix_diff(int x[], int y[], int z[])
{
    for (int i = 0; i < 10; i++)
    {
        z[i] = x[i] - y[i];
        printf("z[%d]=%d\n", i, z[i]);
    }
}
void main()
{
    int a[10] = {4, 19, 10, 16, 21, 31, 41, 52, 32, 39}; // 크기가 10인 배열 a를 임의의 값으로 초기화
    int b[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};    // 크기가 10인 배열 b를 임의의 값으로 초기화
    int c[10];
    matrix_diff(a, b, c);
}
