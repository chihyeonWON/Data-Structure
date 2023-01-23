#include <stdio.h>  // 입출력함수를 사용하기 위함
#include <stdlib.h> // malloc 함수와 free함수를 사용하기 위함
#include <memory.h> // 메모리 조작하는 함수를 사용하기 위함

void main()
{
    int c, i, f, d; // 정수형 변수 c, i, f, d를 선언함
    char *pc;       // 문자형 포인터 pc를 선언함
    int *pi;        // 정수형 포인터 pi를 선언함
    float *pf;      // 실수형 포인터 pf를 선언함
    double *pd;     // double형 포인터 pd를 선언함

    pc = (char *)malloc(100 * sizeof(char));     // 문자 100개 공간 할당
    pi = (int *)malloc(100 * sizeof(int));       // 문자 100개 공간 할당
    pf = (float *)malloc(100 * sizeof(float));   // 문자 100개 공간 할당
    pd = (double *)malloc(100 * sizeof(double)); // 문자 100개 공간 할당

    c = _msize(pc); // pc 동적메모리의 크기를 c에 저장
    i = _msize(pi); // pi 동적메모리의 크기를 i에 저장
    f = _msize(pf); // pf 동적메모리의 크기를 f에 저장
    d = _msize(pd); // pd 동적메모리의 크기를 d에 저장

    printf("pc 메모리의 크기는 %d\n", c); // pc 메모리 크기를 출력
    printf("pi 메모리의 크기는 %d\n", i); // pi 메모리 크기를 출력
    printf("pf 메모리의 크기는 %d\n", f); // pf 메모리 크기를 출력
    printf("pd 메모리의 크기는 %d\n", d); // pd 메모리 크기를 출력

    printf("pc = %lu\n", pc);       // pc의 메모리 값을 출력
    printf("pc+1 = %lu\n", pc + 1); // pc의 메모리 값에 1을 더한 값 출력
    printf("pc-1 = %lu\n", pc - 1); // pc의 메모리 값에 –1을 뺀 값 출력

    printf("pf = %lu\n", pf);
    printf("pf+1 = %lu\n", pf + 1);
    printf("pf-1 = %lu\n", pf - 1);

    printf("pd = %lu\n", pd);
    printf("pd+1 = %lu\n", pd + 1);
    printf("pd-1 = %lu\n", pd - 1);

    free(pc); // pc의 동적메모리 반납
    free(pi); // pi의 동적메모리 반납
    free(pf); // pf의 동적메모리 반납
    free(pd); // pd의 동적메모리 반납
}