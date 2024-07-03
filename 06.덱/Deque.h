#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node{
    Data data;
    struct node * next;
    struct node * prev;
}Node;

typedef struct deque{
    Node * head;
    Node * tail;
}Deque;


void DequeInit(Deque * pdeque);

int DQIsEmpty(Deque * pdeque);

//head에 데이터 추가
void DQAddFirst(Deque * pdeque, Data data);
//tail에 데이터 추가
void DQAddLast(Deque * pdeque, Data data);

//head에 데이터 삭제
Data DQRemoveFirst(Deque * pdeque);
//tail에 데이터 삭제
Data DQRemoveLast(Deque * pdeque);

//head데이터 반환
Data DQGetFrist(Deque * pdeque);
//tail데이터 반환
Data DQGetLast(Deque * pdeque);



#endif