#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#define MAX 100
#define DataType char

typedef struct Tnode
{
    struct Tnode *left;
    DataType *data;
    struct Tnode *right;
} Tnode;

typedef struct LinkedBT
{
    Tnode *root;
} LinkedBT;

//트리 초기화
void init_BT(Tnode **root)
{
    *root = NULL;
}

//트리 초기화
void init(Tnode *root)
{
    root = NULL;
}

//순환 탐색
int searchBT(Tnode *root, DataType data)
{
    int count = 0;
    while (root)
    {
        if (strcmp(data, root->data))
            return count++;
    }
}

// child 노드를 root의 왼쪽 서브트리로 설정
void set_left(Tnode *root, Tnode *child)
{
    /*if (root->left)
    {
        printf("왼쪽 서브트리가 이미 존재한다. \n");
        exit(1);
    }*/
    // else
    root->left = child;
}

// child 노드를 노드 root의 오르쫀 서브트리로 설정
void set_right(Tnode *root, Tnode *child)
{
    /*if (root->right)
    {
        printf("오른쪽 서브트리가 이미 존재한다. \n");
        exit(1);
    }*/
    // else
    root->right = child;
}

// 단말 노드인지 판단
int is_leaf(Tnode *node)
{
    return !node->left && !node->right;
}

// 노드의 데이터를 반환
DataType *get_data(Tnode *node)
{
    if (!node)
    {
        printf("널 노드이므로 데이터를 반환할 수 없습니다.");
        exit(1);
    }
    else
        return node->data;
}

// 노드의 왼쪽 자식 노드를 반환
Tnode *get_left(Tnode *node)
{
    return node->left;
}

Tnode *get_right(Tnode *node)
{
    return node->right;
}

void displayTree(Tnode *root)
{
    if (root)
    {
        displayTree(root->left);
        printf("%s ", root->data);
        displayTree(root->right);
    }
}

void inorder(Tnode *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}

int main()
{
    FILE *fp = fopen("Word.txt", "r");
    if (fp == NULL)
    {
        fputs("파일 열기 오류\n", stderr);
        return 1;
    }

    // 메모리 확보
    char *p_word[MAX] = {0};
    for (int i = 0; i < MAX; ++i)
        p_word[i] = malloc(sizeof(char) * 6); // 5글자 + 널문자 공간 1 = 6

    // 파일 읽기
    for (int i = 1; i < MAX; ++i)
        fscanf(fp, "%s", p_word[i]);

    // 테스트 출력
    for (int i = 1; i < 10; ++i)
        printf("%d: %s\n", i, p_word[i]);

    for (int i = MAX; i < MAX; ++i)
        printf("%d: %s\n", i, p_word[i]);

    int count_line;
    int num;
    LinkedBT BT1, BT2;

    Tnode *node1 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node2 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node3 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node4 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node5 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node6 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node7 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node8 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node9 = (Tnode *)malloc(sizeof(Tnode));

    Tnode *l, *r;

    node1->data = p_word[5];
    node1->left = node1->right = NULL;
    node2->data = p_word[3];
    node2->left = node2->right = NULL;
    node3->data = p_word[8];
    node3->left = node3->right = NULL;
    node4->data = p_word[2];
    node4->left = node4->right = NULL;
    node5->data = p_word[4];
    node5->left = node4->right = NULL;
    node6->data = p_word[7];
    node6->left = node4->right = NULL;
    node7->data = p_word[9];
    node7->left = node4->right = NULL;
    node8->data = p_word[1];
    node8->left = node4->right = NULL;
    node9->data = p_word[6];
    node9->left = node4->right = NULL;
    init(node1);
    set_left(node1, node2);
    set_right(node1, node3);
    set_left(node2, node4);
    set_right(node2, node5);
    set_left(node3, node6);
    set_right(node3, node7);
    set_left(node4, node8);
    set_left(node6, node9);
    char search;
    scanf("%s", &search);
    num = searchBT(&node1, search);
    printf("%d", num);
    // 메모리 해제
    for (int i = 0; i < MAX; ++i)
        if (p_word[i])
            free(p_word[i]);

    return 0;
}
