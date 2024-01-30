#include<stdio.h>

void merge(int arr[],int l, int mid, int r){
    int size1 = mid-l+1;
    int size2 = r-mid;

    int arrr1[size1];
    int arrr2[size2];

    //copy elements of right and left sub-array to the temporary arrays
    for (int i=0;i<size1;i++){
        arrr1[i] = arr[l+i];
    }
    for (int i=0;i<size2;i++){
        arrr2[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=l;

    //merging
    while (i<size1 && j<size2){
        if (arrr1[i] <= arrr2[j]){
            arr[k++] = arrr1[i++];
        }
        else{
            arr[k++] = arrr2[j++];
        }
    }

    //if one of the arrr1 or arrr2 is completely copied while other one is left
    while (i<size1){
        arr[k++] = arrr1[i++];
    }
    while (j<size2){
        arr[k++] = arrr2[j++];
    }
}

void merge_sort(int arr[], int l, int r){
    if (l<r){
        int mid = (l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int array[6] = {6,3,2,8,7,4};

    merge_sort(array,0,5);

    for (int i=0;i<=5;i++){
        printf("%d ",array[i]);
    }
}