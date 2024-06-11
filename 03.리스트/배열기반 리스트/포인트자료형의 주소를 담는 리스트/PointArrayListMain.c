#include<stdio.h>
#include<stdlib.h> //malloc사용시
#include"ArrayList.h"

int main(){

    List PointA;
    ListInit(&PointA);

    Point * point;

    Point Comp;
    SetPointPos(&Comp, 2, 10);


    //Point 데이터 생성 및 리스트에 주소 저장
    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 2,1); //동적할당한 point를 초기화
    LInsert(&PointA,point); //리스트에 동적할당한 Point의 주소를 저장

    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 2,2); 
    LInsert(&PointA,point); 

    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 3,1); 
    LInsert(&PointA,point); 

    point = (Point *)malloc(sizeof(Point));
    SetPointPos(point, 3,2); 
    LInsert(&PointA,point); 


    //저장된 데이터 출력해보기
    if(LFirst(&PointA, &point)){
        ShowPoint(point);

        while(LNext(&PointA, &point)){
            ShowPoint(point);
        }
    }

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
    if(LFirst(&PointA, &point)){
        ShowPoint(point);

        while(LNext(&PointA, &point)){
            ShowPoint(point);
        }
    }
}
