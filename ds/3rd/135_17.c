#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Student
{
    struct Student *llink;
    char *name;
    struct Student *rlink;
} Student;

int main()
{
    Student *head = (Student *)malloc(sizeof(Student));
    head->name = NULL;
    head->llink = head->rlink;
    head->rlink = head->llink;

    Student *student1 = (Student *)malloc(sizeof(Student));
    student1->name = "원치현";
    student1->llink = student1->rlink;
    student1->rlink = student1->llink;

    Student *student2 = (Student *)malloc(sizeof(Student));
    student2->name = "박상훈";
    student2->llink = student1->rlink;
    student2->rlink = student2->llink;

    Student *student3 = (Student *)malloc(sizeof(Student));
    student3->name = "이형원";
    student3->llink = student2->rlink;
    student3->rlink = student1->llink;

    printf("%s-->%s-->%s", student1->name, student2->name, student3->name);

    free(head);
    free(student1);
    free(student2);
    free(student3);
}