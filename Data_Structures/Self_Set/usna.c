#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct Stack{
    int arr[MAX];
    int top;
};

struct Stack*stack=NULL;

void push(int value){
    if(stack->top==MAX-1){
        printf("OverFlow!!");
        return;
    }
    stack->arr[++stack->top]=value;
    printf("Pushed %d onto the stack\n",value);
}

void pop(){
    if(stack->top==-1){
        printf("Stack unterflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void peek(){
    if(stack->top==-1){
        printf("Empty Stack!!");
        return;
    }
    return stack->arr[stack->top];
    printf("\n");
}

void display(){
    if (stack->top == -1){
        printf("Empty Stack!!");
        return;
    }
    printf("Stack Elements : ");
    for (int i = 0; i <= stack->top; i++){
        printf("%d", stack->arr[i]);
    }
    printf("\n");
}
