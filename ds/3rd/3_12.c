#include <stdio.h>  // 입출력함수를 사용하기 위함
#include <stdlib.h> // malloc 함수와 free함수를 사용하기 위함
#include <memory.h> // 메모리 조작하는 함수를 사용하기 위함

void main()
{
    int c, i, f, d;
    char *pc;   // 문자형 포인터 pc를 선언함
    int *pi;    // 정수형 포인터 pi를 선언함
    float *pf;  // 실수형 포인터 pf를 선언함
    double *pd; // double형 포인터 pd를 선언함

    pc = (char *)malloc(100 * sizeof(char));     // 문자 100개 공간 할당
    pi = (int *)malloc(100 * sizeof(int));       // 문자 100개 공간 할당
    pf = (float *)malloc(100 * sizeof(float));   // 문자 100개 공간 할당
    pd = (double *)malloc(100 * sizeof(double)); // 문자 100개 공간 할당

    c = _msize(pc);
    i = _msize(pi);
    f = _msize(pf);
    d = _msize(pd);

    printf("pc 메모리의 크기는 %d\n", c);
    printf("pi 메모리의 크기는 %d\n", i);
    printf("pf 메모리의 크기는 %d\n", f);
    printf("pd 메모리의 크기는 %d\n", d);

    free(pc);
    free(pi);
    free(pf);
    free(pd);
}