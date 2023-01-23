#include <stdio.h>
#include <malloc.h>

typedef struct Student
{
    char *name;
    struct Student *llink;
    struct Student *rlink;
} Student;

/*
    insert_node( NODE **, int)
    insert a key on the back of the linked list.
*/
void insert_node(Student **n, char *name)
{
    Student *new_node = (Student *)malloc(sizeof(Student));
    Student *temp = *n;

    new_node->rlink = NULL;
    new_node->llink = NULL;
    new_node->name = name;

    printf("INSERT %s\n", name);

    // there is not any node.
    if (temp == NULL)
    {
        *n = new_node;

        return;
    }

    // find the last node in the linked list.
    while (temp->rlink != NULL)
    {
        temp = temp->rlink;
    }

    temp->rlink = new_node;
    new_node->llink = temp;
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
        if ((*n)->rlink != NULL)
        {
            *n = (*n)->rlink;

            (*n)->llink = NULL;
        }
        else
        {
            *n = NULL;
        }

        free(temp);

        return 0;
    }

    while (temp->rlink != NULL)
    {
        // if find the key that you want to remove
        if ((temp->rlink)->name == name)
        {
            f = temp->rlink;

            temp->rlink = (temp->rlink)->rlink;
            (temp->rlink)->llink = temp;

            free(f);

            return 0;
        }

        temp = temp->rlink;
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
    Student *p = NULL;

    printf("HEAD > ");

    // print all nodes from the left to the right.
    while (temp != NULL)
    {
        printf("%s ", temp->name);

        p = temp;
        temp = temp->rlink;
    }

    printf(" || ");

    // print all nodes from the right to the left.
    while (p != NULL)
    {
        printf("%s ", p->name);

        p = p->llink;
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

    return 0;
}
