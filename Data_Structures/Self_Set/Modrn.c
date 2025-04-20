#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int main(){
    
    int stack[MAX],i;
    int top=-1;

    printf("\nInsert into stack!!\n");
    if(top>=MAX-1){
        printf("\nStacks full babe!!\n");
    }else{
        stack[++top]=10;;
        printf("\nPushed %d into the stack!!\n",stack[top]);
    }

    printf("\nThe stack displayed!!\n");
    if(top==-1){
        printf("\nStack is empty\n");
    }else{
        for (i = 0; i < top; i++)
        {
            printf("\nStack: %d ", stack[i]);
        }
    }

}