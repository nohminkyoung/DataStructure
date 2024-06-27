#include"LinkedListStack.h"
#include<stdlib.h>
void StackInit(Stack * pstack){
    pstack->head = NULL;
}


int IsStackEmpty(Stack * pstack){
    if(pstack->head == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


void Push(Stack *pstack, Data data){

    Node * newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL){
        fprintf(stderr, "메모리 할당 실패\n");
        exit(-1);
    }


    newnode->data = data;
    newnode->next = NULL;

    if(pstack->head == NULL){
        pstack->head = newnode;
    }
    else{
        newnode->next = pstack->head;
        pstack->head = newnode;
    }
}


Data Pop(Stack * pstack){
    Node * rpos;
    Data rdata;

    if(IsStackEmpty(pstack)){
        printf("데이터 없음\n");
        exit(-1);
    }

    rdata = pstack->head->data;
    rpos = pstack->head;
    pstack->head = pstack->head->next;

    free(rpos);

    return rdata;
}


Data Peek(Stack * pstack){
    if(IsStackEmpty(pstack)){
        printf("데이터 없음\n");
        exit(-1);
    }

    return pstack->head->data;
}