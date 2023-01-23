#define _CRT_SECURE_NO_WARNINGS // visual studio에서 scanf오류를 피하기 위함

#include <stdio.h>  // 문자열입력 함수 사용하기 위함
#include <string.h> // string 라이브러리 함수를 사용하기 위함
#include <stdlib.h> // stdlib 라이브러리 함수를 사용하기 위함
#include <malloc.h> // malloc 라이브러리 함수를 사용하기 위함
#define MAX_SIZE 100  // MAX_SIZE를 100으로 정의함
#define DataType char // DataType을 char로 정의함

// 큐 노드 구조 정의
typedef struct Qnode
{
  DataType *data; //DataType 타입의 data 포인터 선언함
  struct Qnode *link; // Qnode 구조체 타입의 link 포인터 선언함
} Qnode;

// 큐의 헤드 노드 구조 정의
typedef struct LinkedQueue //큐 LinkedQueue를 선언함
{               
  Qnode *front; // Qnode형 포인터 front를 선언함
  Qnode *rear;  // Qnode형 포인터 rear를 선언함
} LinkedQueue;  // 태그이름 LinkedQueue를 선언함

// 큐 초기화하는 init_queue 함수
void init_queue(LinkedQueue *LQ)
{
  LQ->front = LQ->rear = NULL; // 큐의 front와 rear 필드를 NULL으로 설정함
}

// 큐가 포화 상태인지 판단하는 is_queue_full 함수
int is_queue_full(Qnode *node) // 
{
  return node == NULL; // node의 값을 NULL로 초기화함
}

// 큐가 공백 상태인지 판단하는 is_queue_empty 함수
int is_queue_empty(LinkedQueue *LQ)
{
  return LQ->front == NULL; // 큐가 공백 상태일 때 큐의 front 필드를 NULL로 초기화
}

// 큐에 데이터(남학생or여학생)을 삽입하는 enqueue 함수
void enqueue(LinkedQueue *LQ, DataType *data)
{
  Qnode *new = (Qnode *)malloc(sizeof(Qnode)); // 새로운 Qnode타입의 포인터 new 생성
  if (is_queue_full(new))
  {                                                    // 큐가 포화 상태라면
    printf("포화 큐이므로 항목 삽입이 불가능합니다."); // 포화 큐이므로 항목 삽입이 불가능합니다 메시지 출력
    exit(1);
  }
  else
  {
    new->data = data; // new 포인터의 data에 data 값 대입
    new->link = NULL; // new 포인터의 link는 NULL로 초기화
    if (is_queue_empty(LQ)) // 공백큐에 삽입하는 경우
    {
      LQ->front = new; // 큐의 front 필드에 new로 대입
    }
    else
    {
      LQ->rear->link = new; // 일반적인 삽입으로 큐의 rear필드의 link new로 대입
    }
    LQ->rear = new; // 공통된 작업으로 큐의 rear필드를에new 대입
  }
}

// 큐에서 항목 삭제하는 dequeue 함수
DataType dequeue(LinkedQueue *LQ)
{
  if (is_queue_empty(LQ)) // 만약 큐가 공백 상태라면
  {                                                        
    printf("공백 큐이므로 항목 삭제가 불가능합니다. \\n"); // 공백 큐이므로 삭제 불가 메시지 출력
    exit(1);
  }
  else //아니라면
  { 
    Qnode *deleted = LQ->front; // Qnode형의 deleted 포인터에 큐의 front 필드 대입
    DataType *data = deleted->data; // DataType형의 data 포인터에 deleted의 data를 대입
    LQ->front = LQ->front->link; // 큐의 front 필드에 큐의 front필드가 가리키는 link 대입
    if (is_queue_empty(LQ)) // 삭제 후 공백 큐인 경우에
      LQ->rear = NULL; // 큐의 rear를 NULL로 초기화
  }
}

// f와 m이 큐에 저장되었을 때 실행할 Successed 함수
void Successed(LinkedQueue *mq, LinkedQueue *fq)
{
  if (is_queue_empty(mq) || is_queue_empty(fq)) // 두 큐 모두 공백 상태일 때
  {                                                     
    printf("공백 큐이므로 항목 삭제가 불가능합니다. \n"); // 삭제 불가능 메시지 출력
    exit(1);
  }
  else  //아니라면
  {            
    dequeue(mq); // dequeue 함수 실행
    dequeue(fq); // dequeue 함수 실행
  }
}

// f와 m이 큐에 있는 지 확인하는 Matching 함수
void Matching(LinkedQueue *mq, LinkedQueue *fq)
{
  if (mq->front == NULL || fq->front == NULL) // 두 큐에서 front 필드가 NULL이라면
  {                                     
    printf("아직 대상자가 없습니다.\n"); // 대상자가 없습니다 메시지를 출력
  }
  else // 아니라면
  {                                                                                   
    printf("축하합니다. 커플이 탄생했습니다! %s, %s\n", mq->front->data, fq->front->data); // 커플이 탄생했다는 메시지와 함께 큐의 front 필드가 가리키는 data값을 각 큐에서 출력함
    Successed(mq, fq); // 각 큐를 매개변수로 하는 Successed 함수 실행 
  }
}

int main()
{
  LinkedQueue mq, fq; // 남학생큐 mq와 여학생큐 fq LinkedQueue 구조체(연결된 큐) 타입으로 선언
  char name[100][20]; // 이름을 저장할 name을 2차원 문자형배열로 선언함
  char gender; // 성별을 저장할 gender를 선언함

  init_queue(&mq); // mq를 초기화하는 init_queue 함수 실행
  init_queue(&fq); // fq를 초기화하는 init_queue 함수 실행

  for (int i = 0;; i++) // for구문을 실행
  {                                                                       
    printf("미팅 주선 프로그램입니다.(고객이름에 exit 입력 시 종료)\n\n"); // 미팅주선프로그램 메시지 출력
    printf("고객이름: ");                                                  // 고객이름: 을 출력
    scanf("%s", name[i]);                                                  // name을 입력받는 scanf 함수
    getchar(); // 버퍼에 남아있는 것을 내보내기 위한 getchar 함수

    if (strcmp(name[i], "exit")) // name과 exit를 비교해서 같다면
    {                                        
      printf("성별을 입력하세요(f or m): "); //성별을 입력하세요 메시지 출력
      scanf("%c", &gender);                  // 성별을 입력받는 scanf 함수
      getchar(); // 버퍼에 남아있는 것들을 내보내기 위한 getchar 함수

      switch (gender)  // gender 값에 따른 switch 함수
      {                            
      case 'm':                       // gender가 m일 경우
        enqueue(&mq, name[i]);        // 남학생 큐에 이름을 넣는 enqueue 함수 실행
        Matching(&mq, &fq);           // 남학생큐와 여학생 큐를 매개변수로 받는Matching 함수 실행
        break;                        // break 탈출함
      case 'f':                       // gender가 f일 경우
        enqueue(&fq, name[i]);        // 여학생 큐에 이름을 넣는 enqueue 함수 실행
        Matching(&mq, &fq);           // 남학생큐와 여학생 큐를 매개변수로 받는 Matching 함수 실행
        break;                        // break 탈출함
      default:                        // 그 외 기본값으로
        printf("잘못된 입력입니다."); // 잘못된 입력입니다 메시지 출력
        break;                        // break 탈출함
      }
    }
    else  // 그 외 경우에는
    {       
      break; // break 탈출함
    }
  }
}