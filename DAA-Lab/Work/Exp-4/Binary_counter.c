#include <stdio.h>
#include <string.h>

void incrementer(char ch[]){
    for (int i=strlen(ch)-1; i>=0; i--){
        if (ch[i] == '0'){
            ch[i] = '1';
            return;
        }
        else if(ch[i] == '1'){
            ch[i] = '0';
        }
    }
}

int main(){

    int n;
    printf("Enter n (number of increments) : ");
    scanf("%d", &n);

    char counter[n+1];

    for (int i=0;i<n;i++){
        counter[i] = '0';
    }
    counter[n] = '\0';

    //incrementing the counter n times
    for (int i=0; i<n; i++){
        incrementer(counter);
    }
    printf("%s",counter);
}