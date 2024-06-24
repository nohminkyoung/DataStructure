#ifndef __LINKEDLIST_STACK_H__
#define __LINKEDLIST_STACK_H__


#include <stdio.h>

#define TRUE 1 
#define FALSE 0
#define ARR_LEN 100



typedef int Data;


typedef struct node{
    Data data;
    struct node * next;
}Node;

typedef struct {
    Node * head; //데이터는 head에 저장되고 head에 있는 데이터부터 지워짐
}Stack;


void StackInit(Stack * pstack);
int IsStackEmpty(Stack * pstack);
void Push(Stack *pstack, Data data);
Data Pop(Stack * pstack);
Data Peek(Stack * pstack);

#endif