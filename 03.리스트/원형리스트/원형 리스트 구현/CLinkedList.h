#ifndef __CLINKEDLIST__H__
#define  __CLINKEDLIST__H__

typedef int LData;

typedef struct _node{
    LData data;
    struct _node * next;
} Node;

typedef struct _clist{
    Node * tail;
    Node * cur;
    Node * before;
    int numofData;
}List;


void ListInit(List * plist);
void LInsert(List * plist, LData data); //꼬리에 추가
void LInsert_head(List * plist, LData data); //머리에 추가


int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);


#endif