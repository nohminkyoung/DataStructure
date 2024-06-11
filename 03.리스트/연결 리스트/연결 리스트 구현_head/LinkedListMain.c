#include <stdio.h>
#include "LinkedList.h"

//사용자가 정렬의 규칙을 쉽게 변경할 수 있도록 main에 구현
int WhoIsPrecede(int data, int compdata)
{
	if(data < compdata)
		return 0;   //입력된 데이터가 더 작을 경우에 0을 반환
	else
		return 1;    
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	LInsert(&list, 33);  LInsert(&list, 22);
	LInsert(&list, 99);  LInsert(&list, 11);
	LInsert(&list, 66);

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) 
			printf("%d ", data);
	}
	printf("\n\n");

	/***숫자 22를 탐색해 모두 삭제***/
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}