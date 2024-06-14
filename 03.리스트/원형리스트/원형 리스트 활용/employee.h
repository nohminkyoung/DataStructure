#ifndef __EMPOLOYEE_H__
#define __EMPOLOYEE_H__

typedef struct employee{
    char * name; //주소값을 저장하기 떄문에 데이터를 입력할때에는 동적할당이 필요(메모리를 담는 공간을 생성해주기 위함)
    int emnum;
}Emp;


void EmpInit(Emp * pemp, char * name, int num); //emp초기화 함수
void ShowEmpName(Emp * pemp);                   //name을 출력해주는 함수



#endif

