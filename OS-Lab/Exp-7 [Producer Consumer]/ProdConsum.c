#include <stdio.h>
#include<stdlib.h>

int mutex=1, pos=-1,x;
int items[3];

int wait(int s){
    return(--s);
}

int signal(int s){
    return (++s);
}

void producer(){
    mutex=wait(mutex);
    pos=signal(pos);
    if(pos<3){
        printf("\nEnter item");
        scanf("%d",&x);
        printf("\nproducer produces the item %d",x);
        items[pos]=x;
    }
    mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    pos=wait(pos);
    if(pos>=-1){
        x=items[pos+1];
        printf("\n Consumer consume the item %d",x);
    }
    mutex=signal(mutex);
}

void disp(){
    int i;
    for(i=0;i<=2;i++){
        printf("%d\t",items[i]);
    }
}

int main(){
    int n;
    printf("\n 1. producer \n 2. Consumer \n 3. Exit \n 4. Display");
    while(1){
        printf("\n Enter your choice");
        scanf("%d",&n);
        switch(n) {
            case 1:
                if((mutex==1) && (pos<3))
                producer();
                else
                printf("Buffer is full!!");
                break;
            case 2:
                if((mutex==1) && (pos>=0))
                consumer();
                else
                printf("Buffer is empty!!");
                break;
            case 3:
                exit(0);
            case 4:
                disp();
                break;
        }
    }
    return 0;
}
