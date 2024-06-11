//리스트 자료구조 생성에 기반이 되는 main코드

#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList 생성 및 초기화 ***/
	List list;
	int data;
	ListInit(&list);

	/*** 5개의 데이터 추가 ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	/*** 저장된 데이터 전체 출력 ***/
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if(LFirst(&list, &data))    // 첫번째 데이터 조회, 조회성공시 True를 반환하며, True가 되어야 다음 데이터들을 조회 할 수 있음
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    //두번째부터의 데이터를 반복적으로 조회, 마지막 데이터를 넘어선 부분을 조회하면 False를 반환해 반복문이 종료됨
			printf("%d ", data);
	}
	printf("\n\n");

	/***숫자 22를 탐색해 모두 삭제***/
	if(LFirst(&list, &data))	//데이터를 순차적으로 조회를 하여 조회 되었을 때 그 위치에서의 데이터를 삭제하는 방식으로 진행이 됨ㅁ
	{
		if(data == 22)
			LRemove(&list);		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
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