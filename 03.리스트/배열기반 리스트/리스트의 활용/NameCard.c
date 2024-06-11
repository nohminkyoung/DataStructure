#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"NameCard.h"

//NameCard 구조체 변수의 동적 할당 및 초기화 후 주소값 반환
NameCard * MakeNameCard(char * name, char * phone){
    NameCard * namecard;
    namecard = (NameCard *)malloc(sizeof(NameCard));
    strcpy(namecard->name, name);
    strcpy(namecard->phone, phone);

    return namecard;
}

//NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard){
    printf("name : %s\n", pcard->name);
    printf("phone : %s\n\n",pcard->phone);
}

//이름이 같으면 0 아니면 다른값 반환
int NameComp(NameCard * pcard, char * comp){
   return strcmp(pcard->name, comp); //strcmp 자체가 값이 같으면 0을 반환
}

//전화번호 정보 변경
void ChangePhoneNum(NameCard * pcard, char * phone){
    strcpy(pcard->phone, phone);
}