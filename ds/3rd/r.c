#include <stdio.h>
#include <malloc.h>

typedef struct Student
{
    char *name;
    struct Student *link;
} Student;

void insert_node(Student **n, char *name)
{
    Student *new_node = (Student *)malloc(sizeof(Student));
    Student *temp = *n;

    new_node->link = NULL;
    new_node->name = name;

    printf("INSERT %s\n", name);
    // 빈리스트 일때
    if (temp == NULL)
    {
        *n = new_node;
        return;
    }
    // 끝까지 탐색
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new_node;
}

void display_node(Student *n)
{
    Student *temp = n;
    printf("Head >");
    while (temp != NULL)
    {
        printf("%s", temp->name);

        temp = temp->link;
    }
    printf("End. \n");
}
int main()
{
    Student *head = NULL;
    insert_node(&head, "원치현");
    display_node(head);
}