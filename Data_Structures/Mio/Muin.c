#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    return ptr->top==-1;
}

int isFull(struct stack *ptr){
    return ptr->top == ptr->size-1;
}

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Overflow!!");
    }else{
        ptr->arr[++ptr->top]=val;
    }
}

int pop(st) 


int main(){

    

    return 0;
}