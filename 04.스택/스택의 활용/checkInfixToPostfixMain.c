// 중위 -> 후위 변환 함수 확인용
#include <stdio.h>
#include "InfixToPostfix.h"
#include "LinkedListStack.h"


int main(){
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";


    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    printf("%s\n",exp1);
    printf("%s\n",exp2);
    printf("%s\n",exp3);

    return 0;
}