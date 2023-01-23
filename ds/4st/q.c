#define _CRT_SECURE_NO_WARNINGS // visual studio scanf 오류 발생시 추가
#include <stdio.h>              // 입출력함수를 사용하기 위함
#include <stdlib.h>             // stdlib.h 라이브러리 함수를 사용하기 위함
#include <string.h>             // string.h 라이브러리 함수를 사용하기 위함
#include <memory.h>             // memory.h 라이브러리 함수를 사용하기 위함
#include <ctype.h>              // c.type 라이브러리 함수를 사용하기 위함

#define TRUE 1              // TRUE를 1로 정의함
#define FALSE 0             // FLASE를 0으로 정의함
#define MAX_FNAME 10000     // 파일의 최대크기를 10000으로 정의함
#define MAX_WORD_SIZE 10000 // 읽어들인 단어의 최대크기를 10000으로 정의함

// 데이터의 구조
typedef struct Data
{
    char word[MAX_WORD_SIZE]; // 문자형 배열 word를 선언함
    int count;                // 정수형 변수 count를 선언함
} Data;                       // 구조체의 이름을 Data로 선언함

// 노드의 구조
typedef struct Tnode
{
    struct Tnode *right; // 왼쪽 자식 노드를 가리키는 포인터 right를 선언함
    Data data;           // Data의 구조를 가지는 data를 선언함
    struct Tnode *left;  // 오른쪽 자식 노드를 가리키는 포인터 right를 선언함
} Tnode;                 // 구조체의 이름을 Tnode로 선언함

/// 노드 개수 세기
int node_count(Tnode *node)
{
    int count = 0;                                                    // count 값을 0으로 초기화함
    if (node != NULL)                                                 // node가 null이 아니라면
        count = 1 + node_count(node->left) + node_count(node->right); // 자기 자신의 함수를 불러  left,rihgt를 탐색하면서 카운트 값을 증가시킴
    return count;                                                     // count값을 반환함
}

// 두 문자를 크기 비교해주는 compare함수
int compare(Data e1, Data e2)
{
    return strcmp(e1.word, e2.word); /// e1 > e2 -> -1 , e1 == e2 -> 0, e1 < e2 -> 1
}

/// 성공적으로 읽었으면 TRUE를 반환하면서 파일의 문자들을 소문자로 변경함, 파일 끝이라면 FALSE 리턴
int getword(FILE *fd, char *word)
{
    char ch;   //문자형 변수 ch를 선언함
    int i = 0; // 정수형 변수 i를 선언함

    do
    {
        ch = getc(fd);      // fd 파일에서 한 문자를 문자형 변수 ch에 저장
        if (ch == EOF)      // 만약 파일의 끝(EOF)이라면
            return FALSE;   // 종료상태인 FALSE를 넘겨줌
    } while (!isalpha(ch)); /// 첫번째 알파벳 문자가 나올때까지 while문을 실행
    do
    {                     /// 단어 1개를 읽는다.
        ch = tolower(ch); /// 소문자로 변환
        word[i++] = ch;
        ch = getc(fd);
    } while (isalpha(ch)); /// 알파벳 문자이면 계속 while문을 실행
    word[i] = '\0';
    return TRUE; //종료상태 TRUE를 넘겨줌
}

/// 이진탐색트리에 새 단어 추가 또는 기존 단어인 경우 빈도 갱신
Tnode *build_tree(Tnode **root, Data data)
{
    Tnode *p, *q;
    Tnode *new;
    p = *root;
    q = NULL;
    while (p != NULL)
    {
        if (compare(data, p->data) == 0) // compare함수를 이용해 값을 비교하여 0이면 값이 똑같으므로
        {
            p->data.count++; // p의 count값을 1증가

            return p;
        }
        q = p;                          // 값이 같지않다면 root를 p로 옮김
        if (compare(data, p->data) < 0) // compare함수를 이용해 값을 비교하여 0보다 작다면
        {
            p = p->left; // p(root)를 왼쪽으로 이동시킴
        }
        else              // 0보다 크다면
            p = p->right; // p(root)를 오른쪽으로 이동시킴
    }

    new = (Tnode *)malloc(sizeof(Tnode)); // Tnode크기만큼 메모리를 할당해주면서 new라는 새로운 포인터 생성함
    if (new == NULL)                      /// null이면 다시 생성되게끔 함
        return new;
    new->data = data;  // new에 값을 넣어줌
    new->left = NULL;  // left는 null로 초기화함
    new->right = NULL; // right는 null로 초기화함

    if (q != NULL) // q에 값이 들어있다면
    {
        if (compare(data, q->data) < 0)
        {                  ///새로운 값이 들어온다면 new의 count값을 1증가시킴.
            q->left = new; // 새로운 값이 들어온다면
            new->data.count = 1;
        }
        else
        {
            q->right = new;      //새로운 값이 들어온다면
            new->data.count = 1; // new의 count값을 1증가시킴
        }
    }
    else // q에 값이 들어있지 않다면
    {
        *root = new;         //  new는 루트가 되고
        new->data.count = 1; // new의 count값을 1증가시킴
    }
};

// 중위 순회 탐색 함수
void inorder(Tnode *root)
{
    if (root)
    {
        inorder(root->left);                                                      // 왼쪽 서브트리 중위 순회
        printf("\n %s는 %d번 등장합니다.\n ", root->data.word, root->data.count); // word와 count 값을 출력함
        inorder(root->right);                                                     // 오른쪽 서브트리 중위 순회
    }
}

int main()
{
    FILE *fd;           // 파일포인터 fd를 선언함
    Data data;          // 구조체 Data 타입의 data를 선언함
    Tnode *root = NULL; // 트리노드를 NULL로 초기화하면서 선언함

    int flag;     /// 파일 끝 여부 확인하는 정수형 flag 변수 선언함
    int num = 0;  // 문자열 행 번호를 저장할 정수형 변수 num을 선언함
    int pass = 0; // 문자의 존재여부를 판단하는 식별용 정수형 변수 pass를 선언함

    char str[100];            // 한 행의 문자열을 저장할 문자형배열 str를 선언함
    char ans[100];            // 파일내에서 검색할 단어를 입력받아서 저장할 문자형배열 ans를 선언함
    char fname[MAX_FNAME];    /// 파일 이름을 저장할 문자형배열 fname 선언함
    char word[MAX_WORD_SIZE]; /// 읽어들인 단어를 저장할 문자형배열 word 선언함

    printf("파일 이름: "); // 파일이름을 입력하는 printf 함수
    scanf("%s", fname);    // 파일이름을 입력받아서 fname에 저장함

    fd = fopen(fname, "r"); // 받은 파일을 읽기모드로 설정하고 파일포인터 Fd를 반환함

    printf("\n검색할 단어를 입력하세요:"); // 검색할 단어를 입력하는 공간
    scanf("%s", ans);                      // 검색할 문자를 입력받아서 문자형배열 ans에 저장함
    printf("\n");

    if (fd == NULL) // 파일열기에 실패해서 0에 해당하는 NULL이 반환되었다면
    {
        printf("파일을 읽는 데 실패했습니다."); // 파일에 실패하였다라는 문구를 출력함
        return -1;
    }
    // 파일 열기에 성공했을 경우에 밑의 줄을 실행함
    //문자열을 검색해서 몇 번째 줄에 있는지 출력해주는 작업
    while (!feof(fd)) // 파일의 끝에 도달할 때까지 while 문을 실행
    {
        num = num + 1;
        fgets(str, 100, fd); // str에 한 행씩 문자열을 입력받아서 저장함

        if (strstr(str, ans) != NULL) // 입력한 문자가 문자열 행에 존재한다면
        {
            printf("%s는 %d번줄에 있습니다.\n", ans, num); // 문자열 행번호와 입력한 문자를 출력함
            pass = pass + 1;                               // 다음 줄을 의미함
            printf("\n");
        }
    }

    if (pass == 0)
    {                                        // 문자열 행에서 문자를 찾지 못해서 pass가 0이라면
        printf("문자열을 찾을 수 없습니다"); // 문자열을 찾을 수 없다는 문구가 출력됨
        printf("\n");
    }

    if ((fd = fopen(fname, "r")) == NULL)
    {
        fprintf(stderr, "파일을 열 수없습니다.\n");
        return 0;
    }

    printf("각 단어의 빈도수는 다음과 같습니다.\n");

    do
    {
        flag = getword(fd, word); //파일에서 word를 소문자로 바꾼다음 종료상태를 flag에 전달함
        if (flag == FALSE)        // 파일의 끝이라면
            break;                // while 문을 종료함
        strcpy(data.word, word);  /// strcpy를 사용하여 data.word에 word를 넣어줌
        build_tree(&root, data);  /// root의 주소 값과 data를 받아서 빈도수 체크 .
    } while (1);

    inorder(root); // 중위순회함수를 실행해서 word와 그 word의 빈도 수를 최종적으로 출력함
}
