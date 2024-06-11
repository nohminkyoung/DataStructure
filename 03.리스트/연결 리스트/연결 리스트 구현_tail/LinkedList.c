#include<stdio.h>
#include<stdlib.h>

#include"LinkedList.h"

void ListInit(List * plist){
    plist->head = (Node *)malloc(sizeof(Node)); 
    
    plist->tail = plist->head;      //tail은 최초 head와 같은것을 가리킴

    plist->head->next = NULL;                   
    plist->comp = NULL;                         
    plist->numofData = 0;
}

/*** head파일에 정의하지 않아서 LInsert를 통해서만 접근이 가능, 사용자의 직접사용은 불가능함 ***/

void FInsert(List * plist, LData data){         //기본 연결 방식으로 데이터를 삽입

    Node * newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next =NULL;

    plist->tail->next = newnode;
    plist->tail = newnode;

}

void SInsert(List * plist, LData data){ //comp의 규칙이 입력되는 숫자가 비교되는 숫자보다 클 경우 1을 반환

    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    Node * compdata = plist->head; //처음 비교 대상을 head로 해야 비교데이터보다 입력데이터가 작은 경우 연결이 가능함(비교는 head의 다음과)

    while(compdata->next != NULL && plist->comp(newnode->data, compdata->next->data)!=0){ //compdata가 가리키는 다음데이터와 비교
        compdata = compdata->next;
    }

    newnode->next = compdata->next;
    compdata->next = newnode;
    
}
/****************************************************************************/



void LInsert(List * plist, LData data){
    
    if(plist->comp == NULL){                    //정렬규칙이 정해지지 않은경우 head뒤에 연결
        FInsert(plist, data);
    }else{                                      //정렬 규칙이 정해진 경우 규칙에 맞게 정렬
        SInsert(plist, data);
    }

    (plist->numofData)++;                       //저장된 데이터의 개수 증가

}



int LFirst(List * plist, LData * pdata){

    if(plist->head->next == NULL){ //데이터가 하나도 저장이 안된경우
        return 0;
    }
    else{                          // 데이터가 저장되어있는경우
        plist->cur = plist->head->next; //head가 더미노드를 가리키고 있기 때문에, cur을 그 다음 데이터로 이동
        *pdata = plist->cur->data; 

        plist->before = plist->head;

        return 1;
    }

}


int LNext(List * plist, LData * pdata){

    if(plist->cur->next == NULL){ //다음 데이터가 존재하지 않은경우
        return 0;
    }
    else{
        plist->before = plist->cur;
        plist->cur = plist->cur->next;

        *pdata = plist->cur->data;

        return 1;
    }

}

LData LRemove(List * plist){

    Node * rpos = plist->cur; //메모리 헤제를 위해서 cur이 가리키고 있는데 데이터를 기억해야함
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);

    (plist->numofData)--;

    return rdata;

}


int LCount(List * plist){
    return plist->numofData;
}

void SetSortRule(List * plist, int (*comp) (LData d1, LData d2)){
    plist->comp = comp; //정렬의 규칙으로 사용할 함수의 주소를 comp에 저장
}