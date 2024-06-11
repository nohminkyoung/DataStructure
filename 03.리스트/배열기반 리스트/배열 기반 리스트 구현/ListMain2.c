// 생성한 리스트 자료구조를 기반으로 리스트생성 및 합계, 특정 조건을 만족하는 요소 삭제

#include <stdio.h>
#include "ArrayList.h"

int main(){

    List A;
    ListInit(&A);

    int sum, data;


    // 리스트에 1부터 9까지 입력
    for(int i=1; i<=9; i++){
        LInsert(&A, i);
    }

    //리스트를 돌며 총 합 구하기
    if (LFirst(&A,&data)){
        sum += data;

        while(LNext(&A, &data)){
            sum += data;
        }
    }
    printf("리스트 데이터의 총합 : %d\n", sum);

    printf("2와 3의 배수를 삭제\n");
    printf("삭제되는 데이터 : ");

    //2와 3의 배수 삭제
    sum = 0;
    if (LFirst(&A,&data)){
        if (data%2==0 || data%3 ==0){
            LRemove(&A);
            printf(",%d ", data);
        }

        while(LNext(&A, &data)){
            if (data%2==0 || data%3 ==0){
            LRemove(&A);
            printf("%d ", data);
            }
        }
    }

    //삭제 후 리스트의 총 합 구하기
    if (LFirst(&A,&data)){
        sum += data;

        while(LNext(&A, &data)){
            sum += data;
        }
    }
    printf("리스트 데이터의 총합 : %d\n", sum);





}

