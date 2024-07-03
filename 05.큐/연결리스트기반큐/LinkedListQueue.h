#ifndef __LINKEDLISTQUEUE_H__
#define __LINKEDLISTQUEUE_H__

#define ARR_LEN 100
#define TRUE 1
#define FALSE 0

typedef int Data;


typedef struct node{
    Data data;
    struct node * next;
}Node;


typedef struct _queue{

    Node * front;
    Node * rear;

}Queue;
 


void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data Peek(Queue * pq);



#endif