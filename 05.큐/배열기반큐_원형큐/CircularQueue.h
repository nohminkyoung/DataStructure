#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

#define ARR_LEN 100
#define TRUE 1
#define FALSE 0

typedef int Data;


typedef struct _queue{

    int front;
    int rear;
    Data data[ARR_LEN];

}Queue;
 


void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data Peek(Queue * pq);



#endif