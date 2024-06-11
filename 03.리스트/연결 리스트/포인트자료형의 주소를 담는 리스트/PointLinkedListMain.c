// Linkedlist에 Point의 주소값을 담고 Point의 x값에 따라 오름차순으로 정렬하도록 정렬조건을 구현
#include<stdio.h>
#include<stdlib.h> //malloc사용시
#include"LinkedList.h"
int compara_x(LData data, LData compdata){
    if(data->xpos > compdata->xpos){
        return 1;
    }else{
        return 0;
    }
}


int main(){

    List PointA;
    ListInit(&PointA);

    Point * point;

    Point Comp;
    SetPointPos(&Comp, 2, 10);

    SetSortRule(&PointA, compara_x);

    //Point 데이터 생성 및 리스트에 주소 저장
    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 5,1); //동적할당한 point를 초기화
    LInsert(&PointA,point); //리스트에 동적할당한 Point의 주소를 저장

    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 2,2); 
    LInsert(&PointA,point); 

    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 9,1); 
    LInsert(&PointA,point); 

    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 3,2); 
    LInsert(&PointA,point); 


    //저장된 데이터 출력해보기
    printf("저장된 데이터 출력\n");
    if(LFirst(&PointA, &point)){
        ShowPoint(point);

        while(LNext(&PointA, &point)){
            ShowPoint(point);
        }
    }

    printf("비교대상과 같은 x값을 가진 데이터 삭제\n\n");
    //비교대상과 x좌표가 같은 데이터는 삭제하기
    if(LFirst(&PointA, &point)){
        if(PointComp(point, &Comp)==1){
            LRemove(&PointA);
            free(point);}


        while(LNext(&PointA, &point)){
            if(PointComp(point, &Comp)==1){
                LRemove(&PointA);
                free(point);
            }
        }
    }
    

    //삭제 후 데이터 출력해보기
    printf("삭제 후 데이터 출력\n");
    if(LFirst(&PointA, &point)){
        ShowPoint(point);

        while(LNext(&PointA, &point)){
            ShowPoint(point);
        }
    }
}
