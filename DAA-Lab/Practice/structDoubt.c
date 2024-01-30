#include <stdio.h>

typedef struct student{
    int ht;
}student;

typedef struct class{
    int section;
    student student [];
}class;


int printInfo(struct class *cl){
    printf("%d\n\n",cl->section);
    for (int i=1;i<=4;i++){
        printf("\n%d",cl->student[i].ht);
    }
}

int main(){
    class c;
    c.section=18;
    
    c.student[1].ht = 25;
    c.student[2].ht = 35;
    c.student[3].ht = 45;
    c.student[4].ht = 55;
    
    

    printInfo(&c);

    return 0;
}

