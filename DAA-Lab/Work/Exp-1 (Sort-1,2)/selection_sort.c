#include <stdio.h>
int main(){
    int arr[] = {3,5,2,4,1};

    printf("Before sorting: ");
    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    for (int i=0;i<5;i++){
        int smallest = arr[i];
        int index=i;
        for (int j=i+1;j<5;j++){
            if (arr[j]<smallest){
                smallest = arr[j];
                index = j;
            }
        }
        //swap the next element (i'th) with the smallest element (found at index j)

        //printf("swapped %d ",arr[index]);
        //printf("with %d\n",arr[i]);
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }

    printf("\nAfter sorting: ");
    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}