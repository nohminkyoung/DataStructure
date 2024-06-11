#include<stdio.h>

void hanoi(int num, char from, char by, char to){

    if(num==1){
        printf("1번 원반을 %c에서 %c로 이동\n", from, to); // 1번 원반 1개만 남았을 경우 최종적으로 C위치로 이동
    }
    else{
        hanoi(num-1, from, to, by); //n-1개를 보조 기둥으로 이동
        printf("%d번 원반을 %c에서 %c로 이동\n", num, from, to);
        hanoi(num-1, by, from, to); //n-1개를 C로 이동하는 방법
    }
}

int main(){
    int num;
    printf("원하는 원반의 수를 입력하세요\n");
    scanf("%d", &num);

    hanoi(num, 'A', 'B', 'C');

}