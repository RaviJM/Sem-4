#include<stdio.h>

void swap(int arr[]){
    int temp = arr[2];
    arr[2] = arr[5];
    arr[5] = temp;
}

int main(){
    int arr[] = {3,5,2,6,1,7};
    swap(arr);
    
    for (int i=0;i<=5;i++){
        printf("%d ",arr[i]);
    }
}