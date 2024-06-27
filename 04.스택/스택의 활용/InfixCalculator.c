#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "InfixCalculator.h"


int InfixExp(char exp[]){
    
    int result;

    char * copyexp = (char *)malloc(strlen(exp)+1);
    strcpy(copyexp, exp);

    ConvToRPNExp(copyexp);

    result = EvalPRNExp(copyexp);

    return result;

}