#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"CLinkedList.h"


void WhosNightDuty(List plist, char * name, int nextnum);

int main(){

    char empname[50];
    int nexnum;

    //마지막에 데이터를 삭제도 하기위해서 동적으로 할당
    Emp * emp1 = (Emp*)malloc(sizeof(Emp));  
    Emp * emp2 = (Emp*)malloc(sizeof(Emp)); 
    Emp * emp3 = (Emp*)malloc(sizeof(Emp));  
    Emp * emp4 = (Emp*)malloc(sizeof(Emp)); 

    List EmpList;
    LData data;

    ListInit(&EmpList);

    //emp들 초기화
    EmpInit(emp1, "사원1",111);
    EmpInit(emp2, "사원2",222);
    EmpInit(emp3, "사원3",333);
    EmpInit(emp4, "사원4",444);


    //EmpList에 emp의 주소값을 저장
    LInsert(&EmpList,emp1);
    LInsert(&EmpList,emp2);
    LInsert(&EmpList,emp3);
    LInsert(&EmpList,emp4);

    //사원들 순번 확인
    printf("당직근무 순번 : ");
    if(LFirst(&EmpList, &data)){
        printf("%s ",data->name);
        
        for(int i=0;i<LCount(&EmpList)-1; i++){
            LNext(&EmpList, &data);
            printf("-> %s ",data->name);
        }
    }

    printf("\n\n");

    printf("원하는 사람의 이름과 지날 날짜 입력 :\n");
    scanf("%s", empname);
    scanf("%d", &nexnum);


    WhosNightDuty(EmpList, empname, nexnum);


    

}


void WhosNightDuty(List plist, char * name, int nextnum){
    LData data1;
    int found = 0;

    if(LFirst(&plist, &data1)){
        for(int i=0; i<LCount(&plist);i++){
            if(!strcmp(data1->name, name)){
                found = 1;
                break;
            }
            LNext(&plist,&data1);
        }
    }

    if(found){
        for(int i =0; i<nextnum; i++){
            LNext(&plist, &data1);
        }
        ShowEmpName(data1);
    }else{
        printf("잘못된 사람 입력함\n");
    }
    

}

