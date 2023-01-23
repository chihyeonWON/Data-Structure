#include <stdio.h>

typedef struct student /* 구조체 태그 student를 명시함 */
{
    char name[100];     /* 크기가 100인 문자열로 학생의 이름을 나타냄 */
    int student_number; /* 정수형 학생 번호를 나타냄 */
    int score[100];     /* 정수형 배열로 성적을 나타냄 */
} student;              /* 구조체 타입 이름 student를 명시함 */

void main()
{
    struct student students[1000] = {                             /* 크기가 1000인 위에서 생성한 student 구조체를 사용한 배열 students를 선언 */
                                     {"원치현", 20191486, {90}},  /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
                                     {"박상훈", 20191474, {80}},  /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
                                     {"이형원", 20220328, {100}}, /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */
                                     {"이형봉", 20220329, {99}}}; /* 이름, 학번, 성적을 구조체 안의 항목에 맞게 저장 */

    printf("%s, %d, %d", students[1].name, students[1].student_number, students[1].score[0]); /* 배열 students 안의 인덱스 1에 해당하는 이름, 학번, 성적을 출력 */
}