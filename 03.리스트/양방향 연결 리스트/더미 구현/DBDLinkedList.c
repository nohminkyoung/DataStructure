#include<stdio.h>
#include<stdlib.h>
#include"DBDLinkedList.h"


void ListInit(List * plist){
    plist->head = (Node *)malloc(sizeof(Node)); //더미를 추가
    plist->tail = (Node *)malloc(sizeof(Node));

    //head와 tail연결이 필요
    plist->head->prev = NULL;
    plist->tail->next = NULL;
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;

    plist->cur = NULL;
    plist->numofData = 0;
}

//tail에 추가 
void LInsert(List * plist, LData data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;

    newnode->prev = plist->tail->prev;
    plist->tail->prev->next = newnode;
    newnode->next = plist->tail;
    plist->tail->prev = newnode;

    (plist->numofData)++;
}

int LFirst(List * plist, LData * pdata){

    if(plist->head->next == plist->tail){
        return FALSE;
    }

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}


int LNext(List * plist, LData * pdata){
    if(plist->cur->next == plist->tail){
        return FALSE;
    }
    else{
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;
        return TRUE;
    }
}


int LPrevious(List * plist, LData * pdata){ //왼쪽 데이터 출력하는 함수
    if(plist->cur->prev == plist->head){
        return FALSE;
    }
    else{
        plist->cur = plist->cur->prev;
        *pdata = plist->cur->data;
        return TRUE;
    }
}


LData LRemove(List * plist){
    Node * rpos;
    LData rdata;
    rpos = plist->cur;
    rdata = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    plist->cur = plist->cur->prev;
    free(rpos);
    return rdata;

    
}


int LCount(List * plist){
    return plist->numofData;
}