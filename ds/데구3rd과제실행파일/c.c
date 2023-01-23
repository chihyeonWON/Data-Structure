#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define DataType char

typedef struct Male
{
    int front;
    int rear;
    DataType queue[MAX_SIZE];
} Male;

typedef struct Female
{
    int front;
    int rear;
    DataType queue[MAX_SIZE];
} Female;

// 큐 초기화
void init_queue(Male *MQ)
{
    MQ->front = MQ->rear = 0;
}

// 남자를 남자 큐에 삽입
void insert_male(Male *MQ, DataType data)
{
    MQ->rear = (MQ->rear + 1) % MAX_SIZE;
    MQ->queue[MQ->rear] = data;
}

DataType peek(Male *MQ)
{
    return MQ->queue[MQ->front + 1];
}

int main()
{
    char m1[100];
    printf("미팅 주선 프로그램입니다.\n");
    Male male;
    init_queue(&male);
    scanf("고객이름 : %s", &m1);
    insert_male(&male, 10);
    printf("%s", peek(&male));
}