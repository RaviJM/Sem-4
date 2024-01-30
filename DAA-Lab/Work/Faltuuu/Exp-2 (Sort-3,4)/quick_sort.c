#include<stdio.h>

void quick_sort(int arr[], int l, int r){
    int counter = l;
    int pivot = arr[r];

    for (int i=l;i<=r;i++){
        if (arr[i] <= pivot){
            //swap arr[counter] and arr[i]
            int temp = arr[counter];
            arr[counter] = arr[i];
            arr[i] = temp;

            //increment the counter
            counter++;
        }
    }

    //to move the counter on the pivot
    counter--;

    //for left sub-array
    if (l != counter){
        quick_sort(arr, l, counter-1);
    }

    //for right sub-array
    if (counter != r){
        quick_sort(arr, counter+1, r);
    }
}


int main(){
    int size = 10;
    int array[] = {6,3,2,8,7,4,2,1,5,10};

    quick_sort(array,0,size-1);

    for (int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
}


//ALGORITHM
//quick sort is done using recursion
//select last element of array as pivot and rearrange the rest of the array
//rearrange in such a way that all elements <= pivot are to the left and rest are rearranged to the right
//this is done using swapping (using a counter (variable) and the for (loop variable))
//once this is done, call the function for the left sub-array (left to the pivot) and for the right sub-array (right to the pivot)
//during each call, make the pivot as the last element of that sub array
//stopping condition is until counter becomes equal to l (for left array) or equal to r (for right array)
//i.e. when the sub-array has exactly 2 elements in it