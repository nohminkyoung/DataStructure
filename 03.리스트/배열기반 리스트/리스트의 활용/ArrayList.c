#include <stdio.h>
#include "ArrayList.h"
 
// 리스트 구조체 초기화
void ListInit(List * plist){ 

    plist->numOfData = 0;       //데이터를 하나도 저장하지 않은 생태로 초기화
    plist ->curPosition = 0;    //리스트가 초기화되면 0번인덱스를 가리키도록 초기화
}

// 리스트 구조체에 데이터 삽입(순차적으로 삽입됨)
void LInsert(List * plist, LData data){

    if (plist->numOfData > LIST_LEN){   //리스트가 이미 가득 찬 상태 처리
        printf("리스트가 가득찼습니다.\n");
        
        return;
    }

    plist->arr[plist->numOfData] = data;

    (plist->numOfData)++;
}

//리스트내부 배열의 첫번째 데이터를 호출
int LFirst(List * plist, LData * pdata){
    
    if(plist->numOfData == 0){  //아직 데이터가 하나도 삽입되지 않은 경우에는 False를 반환
        return 0;
    }
    
    plist-> curPosition = 0;    //curPosition이 0이 아닌경우 방지
    * pdata = plist->arr[plist-> curPosition];
    
    return 1;                   //데이터 반환이 올바르게 되었다면 True를 반환
}


// 리스트 내부 배열의 두번쨰 데이터부터 호출할 때 사용
int LNext(List * plist, LData * pdata){

    (plist->curPosition)++;     //curPosition가 가리키고 있는 데이터의 위치를 하나 증가시켜줌(다음 데이터)

    if ((plist->numOfData)-1 < plist->curPosition){ //저장된 데이터 이상의 인덱스에 도달했을 때
        printf("더이상 반환할 데이터가 없음\n");
        return 0;
    }

    *pdata = plist->arr[plist->curPosition];
    return 1;


}

// LFirst, LNext로 인해 반환된 값을 삭제하는 기능
LData LRemove(List * plist){
    LData remove = plist->arr[plist->curPosition];  //삭제된 데이터를 반환해주기위해 임시저장
    int i;
    for (i=plist->curPosition ; i<=(plist->numOfData)-1; i++){
        plist->arr[i] = plist->arr[i+1]; // 삭제된 데이터를 기점으로 뒤 데이터들을 한칸씩 당겨 채워줌
    }

    (plist->numOfData)--;       //데이터가 하나 지워져서 빼줌
    (plist->curPosition)--;     //기존에 가리키던 위치에 +1번째 데이터가 채워졌기 때문에 LNext에서 호출 시 그 데이터를 넘어가지 않도록 포인터를 당겨줌

    return remove;
}

//저장된 데이터의 수를 반환
int LCount(List * plist){
    return plist->numOfData;
}