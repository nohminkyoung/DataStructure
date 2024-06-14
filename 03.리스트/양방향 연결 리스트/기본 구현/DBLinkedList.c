#include<stdio.h>
#include<stdlib.h>
#include"DBLinkedList.h"


void ListInit(List * plist){
    plist->head = NULL;
    plist->cur = NULL;
    plist->numofData = 0;
}

//head에 추가 
void LInsert(List * plist, LData data){ 
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;

    newnode->next = plist->head;

    if(plist->head != NULL){
        plist->head->prev = newnode;
    }
    newnode->prev = NULL;
    plist->head = newnode;

    (plist->numofData)++;
    
}


int LFirst(List * plist, LData * pdata){

    if(plist->head->next == NULL){
        return FALSE;
    }

    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}


int LNext(List * plist, LData * pdata){
    if(plist->cur->next == NULL){
        return FALSE;
    }
    else{
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;
        return TRUE;
    }
}


int LPrevious(List * plist, LData * pdata){ //왼쪽 데이터 출력하는 함수
    if(plist->cur->prev == NULL){
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

    if(plist->cur->next == NULL){//맨 뒤 삭제
        plist->cur->prev->next = NULL;
        plist->cur = plist->cur->prev;
        free(rpos);
        return rdata;
    }else if(plist->cur->prev == NULL) { //맨 앞 삭제
        plist->head = plist->cur->next;
        plist->cur->next->prev = NULL;
        plist->cur = plist->head;
        
        free(rpos);
        return rdata;

    }else{
        plist->cur->prev->next = plist->cur->next;
        plist->cur->next->prev = plist->cur->prev;
        plist->cur = plist->cur->prev;
        free(rpos);
        return rdata;
    }

    
}


int LCount(List * plist){
    return plist->numofData;
}