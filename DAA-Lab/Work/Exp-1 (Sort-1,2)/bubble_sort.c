//push heaviest to the end one by one
#include<stdio.h>
int main(){
    int arr[] = {3,5,2,1,4};
    for (int i=0;i<5;i++){
        for (int j=0;j<5-i;j++){
            if (arr[j]>arr[j+1]){
                //swap
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}