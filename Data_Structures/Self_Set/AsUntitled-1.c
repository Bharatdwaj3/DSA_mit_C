#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int i,stack[5];
int top=-1;

int main(){

    int choice, value,n,edit;

    printf("Enter the no of elements that you wanna push: ");
    scanf("%d",&n);

    printf("Enter the values to push in the stack: ");    
    for (i = 0; i < n; i++){
        if (top == MAX - 1){
            printf("Stack is full!!!");
            break;
        }else{
            scanf("%d", &value);
            stack[++top] = value;
        }
    }

    printf("\nThe values of the stack: \n");
    if(top==-1){
        printf("Stack is empty!\n");
    }else{
            for (i = 0; i <= top; i++)
            {
                printf("%d ", stack[i]);
            }
        printf("\n");
    }

    printf("Enter the no of elements that you wanna push: ");
    scanf("%d",&n);

    printf("Enter the values to pop in the stack: ");    
    for (i = 0; i < n; i++){
        if (top ==  - 1){
            printf("Stack is full!!!");
            break;
        }else{
            
        }
    }

    printf("\nThe values of the stack: \n");
    if(top==-1){
        printf("Stack is empty!\n");
    }else{
            for (i = 0; i <= top; i++)
            {
                printf("%d ", stack[i]);
            }
        printf("\n");
    }
}