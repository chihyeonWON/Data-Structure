#include <stdio.h>
#include <malloc.h>

typedef struct Student
{
    char *name;
    struct Student *link;
} Student;

void insert(Student **n, char *name)
{
    Student *new = (Student *)malloc(sizeof(Student));
    Student *temp = *n;

    new->link = NULL;
    new->name = name;

    printf("insert %s\n", name);
    if (temp == NULL)
    {
        *n = new;
        return;
    }
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
}

void display(Student *n)
{
    Student *temp = n;
    printf("Head> ");
    while (temp != NULL)
    {
        printf("%s ", temp->name);
        temp = temp->link;
    }
    printf("End");
}

int delete (Student **n, char *name)
{
    Student *temp = *n;
    Student *deleted = NULL;

    printf("delete %s\n", name);
    if ((*n)->name == name)
    {
        if ((*n)->link != NULL)
        {
            *n = (*n)->link;
        }
        else
        {
            *n = NULL;
        }
        return 0;
    }
    while (temp->link != NULL)
        if ((temp->link)->name == name)
        {
            deleted = temp->link;
            temp->link = (temp->link)->link;
            return 0;
        }
    temp = temp->link;
}

void main()
{
    Student *head = NULL;
    insert(&head, "원치현");
    insert(&head, "이형봉");
    insert(&head, "박상훈");
    display(head);
}