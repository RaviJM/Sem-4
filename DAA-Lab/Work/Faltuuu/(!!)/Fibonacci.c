#include <stdio.h>


void Ifib(int n){
    int a=0;
    int b=1;
    int counter=0;
    while (counter<n){
        printf("%d ",a);
        int temp=a;
        a=b;
        b=temp+b;
        counter++;
    }
}

void Rfib(int n){
    static int term1=0;
    static int term2=1;
    static int term3;

    if (n>0){
        term3 = term1 + term2;
        term1 = term2;
        term2 = term3;

        printf("%d ",term3);

        Rfib(n-1);
    }
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    //Recursive Fibonacci function
    printf("\nUsing Recursive method: ");
    printf("%d %d ",0,1);
    Rfib(n-2); //We have used m-2 because we have 2 numbers already printed here
    

    //Iterative Fibonacci function
    printf("\nUsing Iterative method: ");
    Ifib(n);
}