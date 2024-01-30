#include <stdio.h>

typedef struct student{
    int ht;
}student;


int printInfo(struct student st[]){
    
    for (int i=1;i<=4;i++){
        printf("\n%d",st[i].ht);
    }
}

int main(){
    
    student st[4];

    for (int i=1;i<=4;i++){
        st[i].ht = 10+i;
    }

    printInfo(st);

    return 0;
}

