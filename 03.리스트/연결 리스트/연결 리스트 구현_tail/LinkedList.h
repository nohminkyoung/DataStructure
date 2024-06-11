#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

typedef int LData;

typedef struct _node{ //데이터의 저장 및 연결을 위한 노드
	
	LData data;
	struct _node * next; // 다음 노드의 정보를 저장(=연결을 위함)

}Node;


typedef struct _linkedlist{
	
	Node * head; 
	Node * cur;
	Node * tail;
	Node * before; 
	int numofData; 
	int (*comp)(LData d1, LData d2); 
}List;



void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp) (LData d1, LData d2));



#endif