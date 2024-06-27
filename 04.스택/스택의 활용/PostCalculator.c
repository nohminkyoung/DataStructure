#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"


int EvalPRNExp(char exp[]){

    Stack stack;
    StackInit(&stack);

    int explen = strlen(exp);
    char tk;
    int op1, op2;

    for(int i=0; i<explen; i++){
        tk = exp[i];
        
        if(isdigit(tk)){ // 숫자일 경우에 스택에 담아줌
            Push(&stack, tk-'0'); //- '0'을 해주면 문자를 숫자로 변환
        }
        else{ //연산자일 경우
            op2 = Pop(&stack);
            op1 = Pop(&stack);

            switch(tk){ //연산의 결과를 다시 스택에 넣음
                case '+' :
                    Push(&stack, op1+op2);
                    break;
                case '-' :
                    Push(&stack, op1-op2);
                    break;
                case '*' :
                    Push(&stack, op1*op2);
                    break;
                case '/' :
                    if (op2 == 0) {
                        printf("0으로 나눌 수 없음\n");
                        exit(-1);
                    }
                    Push(&stack, op1/op2);
                    break;
            }

        }
    }

    return Pop(&stack); //최종 결과를 반환

}