#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList ***/
#define LIST_LEN	100
typedef int LData; 			// int부분을 수정해 int형 뿐 아니라 원하는 자료형으로 쉽게 변경해서 쓰기 위함
 
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