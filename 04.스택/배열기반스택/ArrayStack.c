#include<stdio.h>
#include<stdlib.h>
#include"ArrayStack.h"



void StackInit(Stack * pstack){
    pstack->top = -1;
}

int IsStackEmpty(Stack * pstack){
    if(pstack->top == -1){
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void Push(Stack *pstack, Data data){

    if(pstack->top == ARR_LEN){
        printf("저장할 수 있는 범위 초과\n");
    }

    pstack->top += 1;
    pstack->arr[pstack->top] = data;
    

}

Data Pop(Stack * pstack){
    Data rdata;
    
    if(IsStackEmpty(pstack)){
        printf("데이터가 없습니다.\n");
        exit(-1);
    }

    rdata = pstack->arr[pstack->top];
    pstack->top -= 1;

    return rdata;
}   //top의 위치에 따라서 유효한 데이터가 결정되기 때문에 pop된 데이터를 굳이 지워주지 않아도 됨


Data Peek(Stack * pstack){
    if(IsStackEmpty(pstack)){
        printf("데이터가 없습니다.\n");
        exit(-1);
    }

    return pstack->arr[pstack->top];
}