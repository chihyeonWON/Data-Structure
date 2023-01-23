#include <stdio.h>
#include <malloc.h>

typedef struct Student
{
    char *name;
    struct Student *link;
} Student;

void insert_node(Student **n, char *name)
{
    Student *new = (Student *)malloc(sizeof(Student));
    Student *temp = *n;
    printf("insert %s\n", name);

    new->link = NULL;
    new->name = name;

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
    printf("Head > ");
    while (temp != NULL)
    {
        printf("%s ", temp->name);
        temp = temp->link;
    }
    printf(" End");
}

int delete (Student **n, char *name)
{
    Student *temp = *n;
    Student *deleted = NULL;
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

        free(temp);

        return 0;
    }
    while (temp->link != NULL)
    {
        if ((temp->link)->name == name)
        {
            deleted = temp->link;

            temp->link = (temp->link)->link;

            free(deleted);
            return 0;
        }
        temp = temp->link;
    }
}
void main()
{
    Student *head = NULL;
    insert_node(&head, "원치현1");
    insert_node(&head, "원치현2");
    insert_node(&head, "원치현3");
    delete (&head, "원치현3");
    delete (&head, "이이잉");
    display(head);
}