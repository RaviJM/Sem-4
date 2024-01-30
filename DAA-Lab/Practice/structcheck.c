#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;
};

struct node* fun(struct node* n){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = 18;
    ptr->next = NULL;
    n = ptr;
    return n;
}

int main(){
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    n1 = NULL;
    n1=fun(n1);
    printf("%d ",n1 == NULL);
}