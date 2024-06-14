#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"employee.h"


void EmpInit(Emp * pemp, char * name, int num){
    pemp->name = (char *)malloc(strlen(name)+1);
    strcpy(pemp->name, name);
    pemp->emnum = num;
}

void ShowEmpName(Emp * pemp){
    printf("%s\n", pemp->name);
}
