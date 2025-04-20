#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int i,stack[5];
int top=-1;

int main(){

    int choice, value;
    printf("Enter the values to push in the stack: ");
    scanf("%d",&value);

    if(top==MAX-1){
        printf("Stack is full!!!");
    }else{
        stack[++top]=value;
        printf("%d pushed into the stack",value);
    }

    printf("\nThe values of the stack: \n");
    if(top==-1){
        printf("Stack is empty!\n");
    }else{
        printf("Stack elements: ");
        for(i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}