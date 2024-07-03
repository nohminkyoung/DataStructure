#include<stdio.h>
#include<stdlib.h>
#include"LinkedListQueue.h"



void QueueInit(Queue * pq){
    pq->front = NULL;
    pq->rear = NULL;
}


int QIsEmpty(Queue * pq){
    if(pq->front == NULL){ // front의 NULL여부만에 따라서 비어있는지를 판단 가능
        return TRUE;
    }
    else{
        return FALSE;
    }
}


void Enqueue(Queue * pq, Data data){
    Node * newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL){
        fprintf(stderr, "메모리 할당 실패\n");
        exit(-1);
    }

    newnode->next = NULL;
    newnode->data = data;

    if(QIsEmpty(pq)){ //큐가 비어있을 경우 f와 r모두 새로운 노드를 가리킴
        pq->front = newnode;
        pq->rear = newnode;
    }
    else{
        pq->rear->next = newnode;
        pq->rear = newnode;
    }

}

Data Dequeue(Queue * pq){

    Node * rNode;
    Data rdata;

    if(QIsEmpty(pq)){ //큐가 비었다면프로그램 종료
        printf("큐가 비어있습니다.\n");
        exit(-1);
    }
    
    rNode = pq->front;
    rdata = rNode->data;

    pq->front = pq->front->next; //if front가 가리키고 있던 데이터가 마지막 데이터였다면 next가 NULL이기 때문에 NULL을 넣어주는 과정을 고려하지 않아도 됨
                                 // Front의 NULL여부에 따라서 IsEmpty를 고려하기 때문에 rear은 신경쓰지 않아도 됨
    free(rNode);

    return rdata;

}


Data Peek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("큐가 비어있습니다.\n");
        exit(-1);
    }

    return pq->front->data;
}