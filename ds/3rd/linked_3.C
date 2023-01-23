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

    printf("INSERT %s\n", name);

    new_node->rlink = temp;
    new_node->name = name;
    temp->llink = new_node;

    // find the last node.
    while (temp->rlink != *n)
    {
        temp = temp->rlink;
    }

    new_node->llink = temp;
    temp->rlink = new_node;
}

/*
    delete_node( NODE **, int)
    delete the key that you want from the linked list.
    if the key is removed, this function will return 0.
    if it is not, this function will return -1.
*/

char delete_node(Student **n, char *name)
{
    Student *head = (*n)->rlink; // head
    Student *tail = *n;          // tail

    printf("DELETE %s\n", name);

    // if variable 'h' is not starting node.
    while (head != *n)
    {
        if (head->name == name)
        {
            tail->rlink = head->rlink;
            head->rlink->llink = tail;

            free(head);

            return 0;
        }

        head = head->rlink;
        tail = tail->rlink;
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
    Student *temp = n->rlink;

    printf("S > ");

    // display all nodes along next.
    while (temp != n)
    {
        printf("%s ", temp->name);

        temp = temp->rlink;
    }

    printf(" > < ");
    temp = temp->llink;

    // display all nodes along previous.
    while (temp != n)
    {
        printf("%s ", temp->name);

        temp = temp->llink;
    }

    printf(" < E.\n");
}

int main(void)
{
    Student *head = (Student *)malloc(sizeof(Student));

    // initialize the starting node.
    head->name = NULL;
    head->rlink = head;
    head->llink = head;

    insert_node(&head, "원치현");
    insert_node(&head, "박상훈");
    delete_node(&head, "박상훈");
    insert_node(&head, "윤종훈");
    display_node(head);
    return 0;
}
