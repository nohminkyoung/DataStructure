#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#include "Point.h" //Point *를 받기 위해서 필요함

/*** ArrayList ***/
#define LIST_LEN	100
typedef Point * LData; 			// Point의 포인터를 저장하는 리스트로 활용하기 위해서 변경
 
typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;			//저장되는 데이터의 수 기록
	int curPosition;		//데이터의 참조 위치를 기록
} ArrayList;


/*** ArrayList 기능 ***/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif