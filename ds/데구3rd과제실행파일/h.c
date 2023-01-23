#include <stdio.h> // 입출력함수를 사용하기 위함
#include <string.h> // strlen 함수를 사용하기 위함
#include <ctype.h> // tolower 함수를 사용하기위함
#include <stdbool.h> // bool 함수를 사용하기 위함
#define MAX_SIZE 50 // MAX_SIZE 50으로 정의
#define FALSE 0 // FALSE 0으로 정의 
#define TRUE 1 // TRUE 1으로 정의
typedef struct ArrayStack // ArrayStack 스택 생성
{
    int top; // 스택의 top 정보가 들어있는 top변수
    char word[MAX_SIZE]; // 문자형 배열 word 선언
} ArrayStack; // 스택이름을 ArrayStack으로 지정함

// 스택을 초기화하는 init_stack함수
void init_stack(ArrayStack *s)
{
    s->top = -1; // top의 초기값을 –1로 지정함
}

// 스택이 포화상태인지 판단
int is_stack_full(ArrayStack *s)
{
    return (s->top + 1) == MAX_SIZE; // (s->top+1) 값이 MAX_SIZE와 같은 지 비교함
}

// 스택이 공백 상태인지 판단
int is_stack_empty(ArrayStack *s)
{
    return s->top == -1; // (s->top) 값이 -1과 같은 지 비교함
}
// 스택에 삽입
void push(ArrayStack *s, char word)
{
    if (is_stack_full(s)) // 스택이 포화상태이라면
    {
        printf("포화 스택이므로 항목 삽입이 불가능합니다."); //포화상태라는 문구 출력
    }
    else
    {
        s->word[++s->top] = word; // 포화상태가 아니라면 입력한 문자를 스택의 top에 저장함
    }
}

//스택에서 삭제한 것을 반환
char pop(ArrayStack *s)
{
    char temp; // 삭제한 값을 임시로 저장할 temp 변수 선언함
    if (is_stack_empty(s)) // 스택이 공백 상태이라면
    {
        printf("공백 스택이므로 항목 삭제가 불가능합니다."); // 공백상태라는 문구 출력
        return FALSE; // FALSE 값 반환  
    }
    temp = s->word[s->top--]; // temp에 top에서 한 칸 아래 인덱스에 해당하는 값 저장
    return temp; // temp 값을 반환함
}
// 회문이면 TRUE 반환 아니면 FALSE를 반환하는 palindrome 함수 작성
int palindrome(char in_str[])
{
    ArrayStack s; // 스택 s 선언함
    int i; // 정수형 변수 i를 선언함
    char ch, chs; // 문자형 변수 ch, chs를 선언함
    init_stack(&s); // 스택을 초기화함
    int len = strlen(in_str); // 변수 len에 매개변수로 들어온 문자의 길이를 반환해서 저장함
    for (i = 0; i < len; i++) // len의 길이만큼 for 구문을 실행
    {
        ch = in_str[i]; // ch에 in_str의 인덱스에 해당하는 값을 저장
        // 만약 ch가 스페이스거나 구두점이면
        if (ch == ' ' || ch == ',' || ch == '\'')
            continue; // 아래있는 코드는 무시하고 진행함
        ch = tolower(ch); // ch를 소문자로 변경
        push(&s, ch); // 스택에 삽입한다.
    }
    for (i = 0; i < len; i++) // len의 길이만큼 for구문을 실행
    {
        ch = in_str[i]; // ch에 in_str의 인덱스에 해당하는 값을 저장
        // 만약 ch가 스페이스거나 구두점이면
        if (ch == ' ' || ch == ',' || ch == '\'')
            continue; // 아래 있는 코드는 무시하고 진행함
        ch = tolower(ch); // ch를 소문자로 변경
        chs = pop(&s); // 스택에서 문자를 꺼낸다
        if (ch != chs) // ch와 chs와 같지 않다면
            return FALSE; // 실패
    }
    return TRUE; // 성공
}
int main()
{
    char input[MAX_SIZE]; // 문자형 배열 input을 선언함
    printf("입력 단어 : "); // 입력 단어 :를 출력함
    gets(input); // 문자열을 입력받음
    if (palindrome(input)) //입력받은 문자열을 회문인지 검사했을 때 true(1)이 반환된다면
    {
        printf("회문입니다"); // 회문입니다 문구를 출력함
    }
    else
    {
        printf("회문이 아닙니다"); //아니라면 회문이아닙니다 문구를 출력함
    }
}