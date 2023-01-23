#include <stdio.h>
#include <math.h> /* 수학 관련 함수들을 사용하기 위한 라이브러리 */

typedef struct student /* 구조체 태그 student를 명시함 */
{
    char name[100];     /* 크기가 100인 문자열로 학생의 이름을 나타냄 */
    int student_number; /* 정수형 학생 번호를 나타냄 */
    int score[100];     /* 정수형 배열로 성적을 나타냄 */
} student;              /* 구조체 타입 이름 student를 명시함 */

float get_mean(student classmates[], int n) /* 리턴값의 타입을 실수형으로하고 구조체 배열 classmates와 학생수 n을 매개변수로 넘겨받은 함수 */
{
    float total = 0;            /* 성적의 총합을 저장하는 total 변수를 선언하고 초기화 */
    for (int i = 0; i < n; i++) /* 배열의 인덱스를 입력한 학생 수만큼 앞에서부터 탐색하는 for구문 */
    {
        total += classmates[i].score[0]; /* 입력한 학생 수만큼의 성적을 total 변수에 저장 */
    }
    return total / n; /* 성적의 총합을 학생 수로 나눈 평균값을 리턴 */
}

float get_deviation(student classmates[], int n, float average) /* 리턴값의 타입을 실수형으로하고 구조체 배열 classmates와 학생수 n, 실수형 성적의 평균값을 매개변수로 넘겨받은 함수 */
{
    float var, stdev;           /* 분산을 저장하는 var, 표준편차를 저장하는 stdev 선언 */
    float temp = 0;             /* 계산값을 임시로 저장하는 temp 선언하고 초기화 */
    for (int i = 0; i < n; i++) /* 입력한 학생 수만큼의 배열의 인덱스를 탐색하는 for 구문 */
    {
        temp += pow((classmates[i].score[0] - average), 2); /* 성적값과 평균값을 후 나온 값을 제곱하고 나온 값을 저장하는 temp */
    }
    var = temp / n;    /* 분산을 구하기 위해 temp를 학생수로 나누어 var에 저장 */
    stdev = sqrt(var); /* 표준편차를 구하기 위해 분산 var에 루트를 취하는 sqrt함수의 결과값을 stdev에 저장 */
    return stdev;      /* 리턴값으로 표준편차값을 전달 */
}

int main()
{
    int num;                                                      /* 학생 수를 입력받아서 저장할 정수형 변수 num을 선언 */
    float avg;                                                    /* 성적의 평균을 저장할 실수형 변수 avg를 선언 */
    float sd;                                                     /* 성적의 표준편차를 저장할 실수형 변수 sd를 선언 */
    struct student students[1000] = {                             /* 크기가 1000인 위에서 생성한 student 구조체를 사용한 배열 students를 선언 */
                                     {"원치현", 20191486, {90}},  /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
                                     {"박상훈", 20191474, {80}},  /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
                                     {"이형원", 20220328, {100}}, /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
                                     {"이형봉", 20220329, {99}}}; /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
    scanf("%d", &num);                                            /* 학생 수를 입력받아서 num에 저장하는 scanf 함수*/
    avg = get_mean(students, num);                                /* students 배열과 학생의 수를 전달하여 평균을 구하는 함수를 호출하고 리턴값을 avg에 저장 */
    sd = get_deviation(students, num, avg);                       /*students 배열과 학생의 수, 구한 평균을 전달하여 성적의 표준편차를 구하는 함수를 호출하고 리턴값을 sd에 저장 */
    printf("average is = %f, standard deviation is %f", avg, sd); /* 구한 성적의 평균값과 표준편차값을 출력하는 printf함수 */
}