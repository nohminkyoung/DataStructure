#include<stdio.h>

int Bsearch_Recur(int arr[], int first, int last, int target){
    
    int mid = (first + last)/2;

    if (first>last){
        return -1;
    }
    else if(arr[mid]==target){
        return mid;
    }
    else if(target < arr[mid]){
        return Bsearch_Recur(arr,first, mid-1, target);
    }
    else{
        return Bsearch_Recur(arr, mid+1, last, target);
    }

}

int main(){
    int arr[] = {1,3,5,7,9,11,13,15};
    int idx;

    int target;
    printf("찾고싶은 target입력 \n");
    scanf("%d",&target);

    idx = Bsearch_Recur(arr, 0, sizeof(arr)/sizeof(int)-1, target);

    if(idx==-1){
        printf("target없음\n");
    }
    else{
        printf("해당 인덱스 : %d \n", idx);
    }

    return 0;
}