#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__


#include <stdio.h>

#define TRUE 1 
#define FALSE 0
#define ARR_LEN 100



typedef int Data;



typedef struct stack{
    Data arr[ARR_LEN];
    int top; //top index값
}Stack;


void StackInit(Stack * pstack);
int IsStackEmpty(Stack * pstack);
void Push(Stack *pstack, Data data);
Data Pop(Stack * pstack);
Data Peek(Stack * pstack);

#endif