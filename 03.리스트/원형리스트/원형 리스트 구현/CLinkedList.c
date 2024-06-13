#include<stdio.h>
#include<stdlib.h>

#include"CLinkedList.h"


void ListInit(List * plist){
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numofData = 0;

}


void LInsert(List * plist, LData data){
    
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    
    if(plist->tail == NULL){ //첫번째로 추가된 데이터라면 자기 자신을 가리켜야함
        plist->tail = newnode;
        plist->tail->next = newnode;
    }
    else{
        newnode->next = plist->tail->next;
        plist->tail->next = newnode;
        plist->tail = newnode; //head에 추가하는 함수와의 유일한 차이점, 꼬리에 추가하면 새로 추가된것이 tail이 되는것을 주의
    }
    (plist->numofData)++;

}


void LInsert_head(List * plist, LData data){
    
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    
    if(plist->tail == NULL){ //첫번째로 추가된 데이터라면 자기 자신을 가리켜야함
        plist->tail = newnode;
        plist->tail->next = newnode;
    }
    else{
        newnode->next = plist->tail->next;
        plist->tail->next = newnode;
    }
    (plist->numofData)++;

}

int LFirst(List * plist, LData * pdata){

    if(plist->tail == NULL){
        return 0;
    }else{
        plist->cur = plist->tail->next;
        plist->before = plist->tail;

        *pdata = plist->cur->data;

        return 1;
    }

}


int LNext(List * plist, LData * pdata){//무한으로 데이터를 보여줌 (LNext는 무조건 LFirst가 호출된 후에 호출될것이기 때문에 리스트가 비어있는지 확인 안하게 구현)
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;

    return 1;
}

LData LRemove(List * plist){ //삭제할 노드가 tail을 가리키는 경우, 삭제할 노드가 리스트에 홀로 남아있는경우 처리가 필요함
    Node * rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    if(rpos == plist->tail){ //지우는 노드가 tail인 경우
        if(plist->tail == plist->tail->next){ //지우는 노드가 홀로 남아있는 경우
            plist->tail = NULL;
        }
        else{
            plist->tail = plist->before;
        }

    }
    (plist->numofData)--;
    
    return rdata;

}



int LCount(List * plist){
    return plist->numofData;
}