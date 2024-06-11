//1. 총 3명의 전화번호 정보를 리스트에 저장
//2. 특정 이름을 대상으로 탐색을 진행해, 그 사람의 정보 출력
//3. 특정 이름을 대상으로 탐색을 진행해, 그 사람의 전화번호를 변경
//4. 특정 이름을 대상으로 탐색을 진행해 그 사람의 정보를 삭제
//5. 남아있는 모든 사람의 정보를 출력

#include<stdio.h>
#include<stdlib.h>
#include"ArrayList.h"

int main(){
    List PName;
    ListInit(&PName);

    NameCard * card;

    // 3명의 데이터 추가
    card = MakeNameCard("가가가","010-000-0000");
    LInsert(&PName, card);

    card = MakeNameCard("나나나","010-111-1111");
    LInsert(&PName, card);

    card = MakeNameCard("다다다","010-222-2222");
    LInsert(&PName, card);

    // 저장된 모든 사람들의 데이터 확인
    if(LFirst(&PName, &card)){
        ShowNameCardInfo(card);

        while(LNext(&PName, &card)){
            ShowNameCardInfo(card);
        }
    }

    //특정 인물의 전화번호 확인
    printf("다다다의 정보를 출력\n");
    if(LFirst(&PName, &card)){
        if (NameComp(card, "다다다")==0)
            ShowNameCardInfo(card);

        while(LNext(&PName, &card)){
            if (NameComp(card, "다다다")==0){
                ShowNameCardInfo(card);
                break;}
        }
    }

    //특정 인물의 전화번호 변경
    printf("나나나의 정보를 출력\n");
    if(LFirst(&PName, &card)){
        if (NameComp(card, "나나나")==0){
                ChangePhoneNum(card, "010-9999-9999");
                ShowNameCardInfo(card);}

        while(LNext(&PName, &card)){
            if (NameComp(card, "나나나")==0){
                    ChangePhoneNum(card, "010-9999-9999");
                    ShowNameCardInfo(card);
                break;}
        }
    }

    //특정인물 삭제
    printf("가가가를 삭제\n");
    if(LFirst(&PName, &card)){
        if (NameComp(card, "가가가")==0){
                card = LRemove(&PName);
                free(card);
            }

        while(LNext(&PName, &card)){
            if (NameComp(card, "가가가")==0){
                    card = LRemove(&PName);
                    free(card);
                break;}
        }
    }


    // 남은 사람들의 데이터 확인
    printf("남은 사람들 데이터 확인\n");
    if(LFirst(&PName, &card)){
        ShowNameCardInfo(card);

        while(LNext(&PName, &card)){
            ShowNameCardInfo(card);
        }
    }


}