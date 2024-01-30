#include <stdio.h>

typedef struct arr{
    int ele;
}arr;

void setter(struct arr arr[]){
    for (int i=1;i<=4;i++){
        arr[i].ele = 18;
    }
}

void printer(struct arr arr[]){
    for (int i=1;i<=4;i++){
        printf("\n%d\n",arr[i].ele);
    }
}

int main(){
    arr arr[5];
    setter(arr);
    printer(arr);
    return 0;
}