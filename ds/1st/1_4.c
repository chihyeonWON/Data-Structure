#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void search(int x[10], int a, int b) /* 매개변수로 배열 이름, 찾고자하는 값, 요소의 위치를 받는 search 함수 */
{
    for (int b = 0; b < 10; b++) /* 받은 배열의 요소를 0부터 9까지 탐색 */
    {
        if (x[b] == a) /* 만약 배열의 요소값과 찾고자하는 값이 같다면 */
        {
            printf("Index is %d", b); /* 찾고하자하는 값의 위치를 출력 */
        }
    }
}

void main()
{
    int a[10] = {23, 45, 12, 34, 65, 25, 89, 61, 26, 11}; /* 크기가 10인 배열 a를 주어진 값들로 초기화*/
    int num, b;                                           /* 찾고자하는 값을 저장하는 변수 num과 요소의 위치를 저장하는 변수 position과 함수의 리턴값을 받는 변수 b를 선언 */
    int position = NULL;                                  /* position값 초기화 */
    scanf("%d", &num);                                    /* 찾고자하는 값을 받아서 num에 저장하는 scanf함수 */
    search(a, num, position);                             /* search함수의 매개변수로 배열 이름, 찾고자하는값, 요소의 위치를 넘겨주고 리턴값을 b에 저장 */
}