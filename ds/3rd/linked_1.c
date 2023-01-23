#include <stdio.h>
#include <malloc.h>

typedef struct Student
{
    char *name;
    struct Student *link;
} Student;

/*
    insert_node( NODE **, int)
    insert a key on the back of the linked list.
*/
void insert_node(Student **n, char *name)
{
    Student *new_node = (Student *)malloc(sizeof(Student));
    Student *temp = *n;

    new_node->link = NULL;
    new_node->name = name;

    printf("INSERT %s\n", name);

    // there is not any node.
    if (temp == NULL)
    {
        *n = new_node;

        return;
    }

    // find the last node in the linked list.
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new_node;
}

/*
    delete_node( NODE **, int)
    delete the key that you want from the linked list.
    if the key is removed, this function will return 0.
    if it is not, this function will return -1.
*/
int delete_node(Student **n, char *name)
{
    Student *temp = *n;
    Student *f = NULL;

    printf("DELETE %s\n", name);

    // if the key that you want to remove is located firstly.
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
        // if find the key that you want to remove
        if ((temp->link)->name == name)
        {
            f = temp->link;

            temp->link = (temp->link)->link;

            free(f);

            return 0;
        }

        temp = temp->link;
    }

    printf("Can't find the key!\n");

    return -1;
}

/*
    display_node( NODE *)
    display all node in the linked list.
*/
void display_node(Student *n)
{
    Student *temp = n;

    printf("HEAD > ");

    while (temp != NULL)
    {
        printf("%s ", temp->name);

        temp = temp->link;
    }

    printf(" END.\n");
}

int main(void)
{
    Student *head = NULL; // HEAD

    insert_node(&head, "원치현");
    insert_node(&head, "박상훈");
    insert_node(&head, "윤종훈");
    display_node(head);
    delete_node(&head, "박상훈");
    display_node(head);
}
