#include<stdio.h>

int Bsearch(int arr[], int len, int target){

    int first = 0;
    int last = len-1;
    int mid;

    while(first<=last){
        mid = (first+last)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(target > arr[mid]){
            first = mid+1;        
        }
        else if(target < arr[mid]){
            last = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,3,5,7,9,11,13,15};
    int idx;

    int target;
    printf("찾고싶은 target입력 \n");
    scanf("%d",&target);

    idx = Bsearch(arr, sizeof(arr)/sizeof(int), target);

    if(idx==-1){
        printf("target없음\n");
    }
    else{
        printf("해당 인덱스 : %d \n", idx);
    }

    return 0;
}