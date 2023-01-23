#define _CRT_SECURE_NO_WARNINGS // visual studio에서 scanf오류를 피하기 위함

#include <stdio.h> // 문자열입력 함수 사용하기 위함
#include <string.h> // string 라이브러리 함수를 사용하기 위함
#include <stdlib.h> // stdlib 라이브러리 함수를 사용하기 위함
#define MAX_SIZE 100 // MAX_SIZE를 100으로 정의함
#define DataType char // DataType을 char로 정의함

typedef struct ArrayQueue {   // 큐 ArrayQueue 선언함
	int front; // 정수형 front정보를 선언함
	int rear; // 정수형 rear정보를 선언함
	DataType *queue[MAX_SIZE]; // 문자형 배열 queue를 선언함
} ArrayQueue; // 태그이름 ArrayQueue를 선언함

// 큐 초기화하는 함수
void init_queue(ArrayQueue *AQ) {
	AQ->front = AQ->rear = 0; // front와 rear값을 0으로 함 
}

// 큐가 포화 상태인지 판단
int is_queue_full(ArrayQueue* AQ) {
	return ((AQ->rear + 1) % MAX_SIZE) == AQ->front; // 큐가 포화상태라면 rear에 1을 더하고 MAX_SIZE로 나누었을 때 나머지 값이 front 값과 같음
}
// 큐가 공백 상태인지 판단하는 함수
int is_queue_empty(ArrayQueue* AQ) {
	return AQ->front == AQ->rear; // 큐가 공백 상태일 때 front값과 rear값이 같음
}

// 큐에 삽입하는 함수
void enqueue(ArrayQueue* AQ, DataType *data) {
	if (is_queue_full(AQ)) {           // 큐가 포화 상태라면
  printf("포화 큐이므로 항목 삽입이 불가능합니다."); // 포화 큐이므로 항목 삽입이 불가능합니다 메시지 출력
  exit(1); 
	}
	else {
  AQ->rear = (AQ->rear + 1) % MAX_SIZE; // rear를 rear+1을 MAX_SIZE로 나눠서 나머지의 값의 위치로 이동
  AQ->queue[AQ->rear] = data; // queue의 rear위치에 data값을 넣어줌
	}
}

// 큐에서 항목 삭제(실제로 삭제는 안함)
void dequeue(ArrayQueue* AQ) {
	if (is_queue_empty(AQ)) {  // 만약 큐가 공백 상태라면
  printf("공백 큐이므로 항목 삭제가 불가능합니다. \\n"); // 공백 큐이므로 삭제 불가 메시지 출력
  exit(1);
	}
	else {   //아니라면
  AQ->front = (AQ->front + 1) % MAX_SIZE; // front는 front+1을 MAX_SIZE로 나눈나머지 값으로 치환
	}
}

// f와 m이 큐에 저장되었을 때 실행할 함수 
void Successed(ArrayQueue* mq, ArrayQueue* fq) {
	if (is_queue_empty(mq) || is_queue_empty(fq)){ // 두 큐 모두 공백상태일 때
  printf("공백 큐이므로 항목 삭제가 불가능합니다. \n"); // 삭제 불가능 메시지 출력
  exit(1);
	}
	else { //아니라면
  dequeue(mq); // dequeue 함수 실행
  dequeue(fq); // dequeue 함수 실행
	}
}

// f와 m이 큐에 있는 지 확인하는 함수
void Matching(ArrayQueue* mq, ArrayQueue* fq) {
	if (mq->front == mq->rear || fq->front == fq->rear) { // 두 큐에서 front와 rear값이 같지 않다면
  printf("아직 대상자가 없습니다.\n"); // 대상자가 없습니다 메시지 출력
	}
	else { // 아니라면
  printf("축하합니다. 커플이 탄생했습니다! %s 와(과) %s\n", mq->queue[(mq->front + 1) % MAX_SIZE], fq->queue[(fq->front + 1) % MAX_SIZE]); // 큐의 front+1을 MAX_SIZE로 나눈 나머지 값을 각 큐에서 출력
  Successed(mq, fq); // Successed 함수 실행
	}
}

int main() {
	ArrayQueue mq, fq; // 남학생큐 mq와 여학생큐 fq를 ArrayQueue 구조체(큐) 타입으로 선언
	char name[20][20]; // 이름을 저장할 name을 2차원 문자형배열로 선언함
	char gender; // 성별을 저장할 gender를 선언함

	init_queue(&mq); // mq를 초기화하는 함수 실행
	init_queue(&fq); // fq를 초기화하는 함수 실행

	for (int i = 0; strcmp(name[i], "exit"); i++) { // name이 exit가 되기 전 까지 for구문을 실행
  printf("미팅 주선 프로그램입니다.(고객이름에 exit 입력 시 종료)\n\n"); // 미팅주선프로그램 메시지 출력
  printf("고객이름: "); // 고객이름: 을 출력
  scanf(" %s", name[i]); // name을 입력받는 scanf 함수
  fflush(stdin); //버퍼에 남아있지 않게 내보내는 fflush

  if (strcmp(name[i], "exit")) { // name과 exit를 비교해서 같다면
  printf("성별을 입력하세요(f or m): "); //성별을 입력하세요 메시지 출력
  scanf(" %c", &gender); // 성별을 입력받는 scanf 함수
  fflush(stdin); // 버퍼에 남아있지 않게 내보내는 fflush

  switch (gender) { //gender 값에 따른 switch 함수
  case 'm': //gender가 m일 경우
  enqueue(&mq, name[i]); // 남학생큐에 이름을 넣는 enqueue 함수 실행 
  Matching(&mq, &fq); // 남학생큐와 여학생 큐를 매개변수로 받는 Matching 함수 실행
  break; // break 탈출함
  case 'f': // gender가 f일 경우
  enqueue(&fq, name[i]); // 여학생큐에 이름을 넣는 enqueue 함수 실행
  Matching(&mq, &fq); // 남학생큐와 여학생 큐를 매개변수로 받는 Matching 함수 실행
  break; // break 탈출함
  default: // 그 외 기본값으로
  printf("잘못된 입력입니다."); // 잘못된 입력입니다 메시지 출력
  break; // break 탈출함
  }
  }
  else { // 그 외 경우에는
  break; // break 탈출함
  }
	}
}