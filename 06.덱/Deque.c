#include<stdio.h>
#include<stdlib.h>
#include"Deque.h"



void DequeInit(Deque * pdeque){
    pdeque->head = NULL;
    pdeque->tail = NULL;
}


int DQIsEmpty(Deque * pdeque){
    if(pdeque->head == NULL){ //head 가 NULL일 경우 비어있다고 판단
        return TRUE;
    }
    else {
        return FALSE;
    }
}


void DQAddFirst(Deque * pdeque, Data data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = pdeque->head; //만약 큐가 비어있어도 head가 NULL이기 때문에 상관 x
    newnode->prev = NULL;

    if(DQIsEmpty(pdeque)){ //처음 입력되는 데이터인 경우 tail도 newnode를 가리킴
        pdeque->tail = newnode;
    }
    else{ //head가 존재했다면 기존 head의 prev가 이전 노드를 가리켜야함
        pdeque->head->prev = newnode;
    }

    pdeque->head = newnode;
}


void DQAddLast(Deque * pdeque, Data data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = pdeque->tail;

    if(DQIsEmpty(pdeque)){
        pdeque->head = newnode;
    }
    else{
        pdeque->tail->next = newnode;
    }
    pdeque->tail = newnode;
}


Data DQRemoveFirst(Deque * pdeque){
    Node * rnode;
    Data rdata;

    if(DQIsEmpty(pdeque)){
        printf("큐가 비어있습니다.\n");
        exit(-1);
    }

    rnode = pdeque->head;
    pdeque->head = pdeque->head->next;


    rdata = rnode->data;
    free(rnode);

    if(pdeque->head == NULL){ //큐 내부에 데이터가 다 지워져 head가 NULL이 된 상환
        pdeque->tail = NULL; //tail도 NULL
    }
    else{ //head가 NULL을 가리킬 경우 prev 설정을 못하기 때문에 이 때 prev를 NULL로
        pdeque->head->prev = NULL;

    }

    return rdata;
}



Data DQRemoveLast(Deque * pdeque){
    Node * rnode;
    Data rdata;

    if(DQIsEmpty(pdeque)){
        printf("큐가 비어있습니다.\n");
        exit(-1);
    }

    rnode = pdeque->tail;
    pdeque->tail = pdeque->tail->prev;


    rdata = rnode->data;
    free(rnode);

    if(pdeque->tail == NULL){ //큐 내부에 데이터가 다 지워져 tail이 NULL이 된 상환
        pdeque->head = NULL; //head도 NULL
    }
    else{ //tail이 NULL을 가리킬 경우 next 설정을 못하기 때문에 이 때 next를 NULL로
        pdeque->tail->next = NULL;

    }

    return rdata;
}

Data DQGetFrist(Deque * pdeque){
    if(DQIsEmpty(pdeque)){
        printf("큐가 비어있습니다.\n");
        exit(-1);
    }
    
    return pdeque->head->data;
}
Data DQGetLast(Deque * pdeque){
    if(DQIsEmpty(pdeque)){
        printf("큐가 비어있습니다.\n");
        exit(-1);
    }
    
    return pdeque->tail->data;
}