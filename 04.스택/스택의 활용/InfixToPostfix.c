#include <stdio.h>
#include <string.h>
#include <ctype.h> //isdigit 사용을 위함
#include <stdlib.h>
#include "LinkedListStack.h"
#include "InfixToPostfix.h"

// 연산의 우선순위를 부여하는 함수
// *,/의 우선순위가 가장높고 +-, (는 생성되면 그 자리에 유지되야하기 때문에 가장 낮은 우선순위를 부려
//ConvToRPNExp의 기능을 돕는 헬퍼함수
int GetOpPrec(char op){

    switch(op){
        case '*':
        case '/':
            return 5;
        
        case '+':
        case '-':
            return 3;
        
        case '(' :
            return 1;
    }

    return -1;
}

//두 연산자의 우선순위를 비교하는 함수
//기존 스택에 위치한 연산자(op1)의 우선순위가 크면 1
int WhoPrecOp(char op1, char op2){
    int op1prec = GetOpPrec(op1);
    int op2prec = GetOpPrec(op2);

    if(op1prec > op2prec){
        return 1;
    }else if(op1prec < op2prec){
        return -1;
    }else {
        return 0;
    }
}

//재정렬하는 함수
void ConvToRPNExp(char exp[]){

    int explen = strlen(exp);
    char tk, popop;
    int idx=0; //convexp에 데이터를 넣기 위한 인덱스

    Stack stack;
    StackInit(&stack);
    char * convexp = (char *)malloc(explen+1);
    memset(convexp, 0, sizeof(char)*explen+1); //convexp 내부의 값을 0으로 초기화 하는 작업

    for(int i = 0; i<explen; i++){
        tk = exp[i];

        if(isdigit(tk)){ // tk 가 숫자라면 convexp에 넣어줌
            convexp[idx] = tk;
            idx++;
        }
        else{   //tk가 연산자라면 스택에 데이터와 비교 , (,),연산자 일때 해결방식을 달리함

            if(tk=='('){ //(라면 무조건 스택에 넣어줌
                Push(&stack, tk);
            }
            else if(tk==')'){ //)라면 (를 만날 때 까지 스택에 데이터를 문자열로 옮겨줌
                while(1){
                    popop = Pop(&stack);
                    if(popop == '('){
                        break;
                    }
                    convexp[idx++] = popop;
                    
                }
            }
            else{ // 연산자를 만났을 때 
                while(!IsStackEmpty(&stack)&&WhoPrecOp(Peek(&stack),tk)>0){ //스택이 비어있지 않고, 스택 내부의 연산자의 우선순위가 높다면
                    convexp[idx++] = Pop(&stack);  //기존 연산자를 convexp로
                }
                Push(&stack, tk);   //tk를 스택에 저장

            }


        }
    }
    while(!IsStackEmpty(&stack)){ //for루프를 다 돌았다면 스택에 쌓인 연산자를 모두 convexp로 이동시켜야함
        convexp[idx++] = Pop(&stack); 
    }

    convexp[explen+1] = '\0';

    strcpy(exp, convexp);
    free(convexp);
}