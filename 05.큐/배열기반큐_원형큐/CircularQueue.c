#include<stdio.h>
#include<stdlib.h>
#include"CircularQueue.h"


// 인덱스를 다음으로 넘겨주는 함수
int NextIndex(int pos){
    if(pos == ARR_LEN-1){ //pos가 배열의 마지막 인덱스라면 0번인덱스로 보내야함
        return 0;
    }
    else{
        return pos+1;
    }
}

//큐를 초기화 하는 함수
void QueueInit(Queue * pq){
    //front 와 rear 모두 0을 가리키도록
    pq -> front = 0;
    pq -> rear = 0;
}

//큐가 비었는지 확인하는 함수(비어있다면 True)
int QIsEmpty(Queue * pq){
    if(pq->front == pq->rear){//front와 rear가 같다면 비어있는 것
        return TRUE;
    }
    else{
        return FALSE;
    }

}

//데이터를 추가하는 함수
void Enqueue(Queue * pq, Data data){
    if(pq->front == NextIndex(pq->rear)){ //front와 rear+1이 같다면 가득 찬 큐
        printf("큐에 빈 공간이 없습니다. \n");
        exit(-1);
    }

    pq->rear = NextIndex(pq->rear); //rear를 한칸 이동 후 데이터 입력
    pq->data[pq->rear] = data;
}

//데이터를 삭제하는 함수
Data Dequeue(Queue * pq){
    if(QIsEmpty(pq)){
        printf("큐가 비어있습니다. \n");
        exit(-1);
    }

    pq->front = NextIndex(pq->front);

    return pq->data[pq->front]; //front가 가리키게되면 무의미한 데이터가 된 것이므로 삭제된 데이터는 front가 가리키는 데이터
}

Data Peek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("큐가 비어있습니다. \n");
        exit(-1);
    }

    return pq->data[NextIndex(pq->front)];
}


