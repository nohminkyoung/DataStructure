#ifndef __DBLINKEDLIST_H__
#define __DBLINKEDLIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node{
    LData data;
    struct _node * next;
    struct _node * prev; //반대방향으로의 연결을 위해 구현
} Node;

typedef struct DBLinkedList{

    Node * head;
    Node * cur;
    Node * tail; //꼬리 추가
    int numofData;
}List;


void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
int LPrevious(List * plist, LData * pdata); //왼쪽 데이터 출력하는 함수

LData LRemove(List * plist);
int LCount(List * plist);


#endif