// 후위변환 계산 여부 확인용
#include <stdio.h>
#include "PostCalculator.h"

int main(){
    char exp1[] = "42*8+";
    char exp2[] = "123+*4/";

    printf("%s = %d \n", exp1, EvalPRNExp(exp1));
    printf("%s = %d \n", exp2, EvalPRNExp(exp2));

    return 0;
}