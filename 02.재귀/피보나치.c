#include<stdio.h>

int fibo(int num){
    if(num==0){
        return 0;
    }else if(num==1){
        return 1;
    }else{
        return fibo(num-1)+fibo(num-2);
    }
}


int main(){

    int i;

    for (i=0;i<7;i++){
        printf("%d ", fibo(i));
    }

    return 0;
}