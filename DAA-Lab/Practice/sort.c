#include <stdio.h>
int main(){
    int arr[] = {3,5,1,4,2};

    for (int i=0;i<5;i++){
        int item = arr[i];
        int counter = i-1;
        while (arr[counter] > item){
            arr[counter+1] = arr[counter];
            printf("shifted %d to the right\n", arr[counter]);
            counter--;
        }
        arr[counter+1] = item;
        printf("\n");
    }
      
    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}