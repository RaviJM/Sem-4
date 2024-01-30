#include<stdio.h>  
struct address   
{  
     
    int pin;  
    
};  
struct employee  
{  
    int name;
    struct address add;  
};  
void display(struct employee);  
void main ()  
{  
    struct employee emp;  
    emp.name = 18;
    emp.add.pin = 361142;
    display(emp);  
}  
void display(struct employee emp)  
{  
  printf("Printing the details....\n");  
  printf("%d %d",emp.name,emp.add.pin);  
}