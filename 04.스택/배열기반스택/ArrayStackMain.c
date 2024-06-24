#include<stdio.h>
#include"ArrayStack.h"

int main(){

    Stack stack;
    StackInit(&stack);

    Push(&stack, 5); Push(&stack, 4);
    Push(&stack, 3); Push(&stack, 2);
    Push(&stack, 1);

    printf("%d\n", Peek(&stack));

    while(!IsStackEmpty(&stack)){
        printf("%d ",Pop(&stack));
    }

    return 0;
}