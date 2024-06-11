#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include"Point.h"

typedef Point * LData; //Node에 담기는 데이터의 성격을 Point의 주소값으로

typedef struct _node{ //데이터의 저장 및 연결을 위한 노드
	
	LData data;
	struct _node * next; // 다음 노드의 정보를 저장(=연결을 위함)

}Node;


typedef struct _linkedlist{
	
	Node * head; // 리스트의 가장 앞부분을 나타내는 포인터
	Node * cur;  // 현재 가리키고 있는 데이터를 나타내는 포인터
	Node * before; // 이전에 가리킨 데이터(삭제 후 연결을 위함)
	int numofData; // 데이터의 수
	int (*comp)(LData d1, LData d2); //정렬기준함수를 가리키는 포인터
}List;



void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp) (LData d1, LData d2));



#endif