#include<stdio.h>
#include "InfixCalculator.h"

int main(){

    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)*3)*(5-2)";

    printf("%s = %d \n", exp1, InfixExp(exp1));
    printf("%s = %d \n", exp2, InfixExp(exp2));
    printf("%s = %d \n", exp3, InfixExp(exp3));

    return 0;
}