#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	//5개의 데이터 입력
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert_head(&list, 2);
	LInsert_head(&list, 1);

    printf("저장된 데이터의 개수 : %d\n", LCount(&list));
	
	// 데이터 출력해보기 //
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)*3-1; i++) //3회 반복 출력해보기
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n\n");

	//2의 배수 삭제하기//
	if(LFirst(&list, &data))
	{  
		if(data%2 == 0)
			LRemove(&list);
		
		for(i=0; i < LCount(&list)-1; i++) //한바퀴 돌면서 확인
		{
			LNext(&list, &data);
			if(data%2 == 0)
				LRemove(&list);
		}
	}

    printf("2의 배수 삭제 후 데이터의 수 : %d\n", LCount(&list));
	// 삭제 후 데이터 출력하기 //
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)-1; i++)
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}

	return 0;
}