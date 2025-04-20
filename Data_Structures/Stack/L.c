#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node*top=NULL;

void push(int value){
    struct Node*newNode=(struct  Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory Allocated!!");
        return;
    }
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("%d pushed onto the stack!!\n",value);
}

int pop() {
    if(top==NULL){
        return -1;
    }
    struct Node*temp=top;
    int popVal=top->data;
    top=top->next;
    free(temp);
    return popVal;
}

int peek() {
    if(top==NULL){
        printf("Stack is Empty!!\n");
        return -1;
    }
    return top->data;
}

int isEmpty(){
    return top==NULL;
}

void display() {
    if(top==NULL){
        printf("Stackho ij Emptya wa!!");
    }else{
        struct Node *temp=top;
        printf("Stack: ");
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){

    int choice, value;
    while(1){
        printf("\nStack operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Empty??\n");
        printf("5. Exit\n");
        printf("6. Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter your value to be pushed: ");
                scanf("%d",&value);
                push(value);
                
                break;
            
            case 2:
               value = pop();
               if(value!=-1){
                printf("Popped %d\n",value);
               }
                break;
            case 3:
                value = peek();
                if (value != -1)
                {
                    printf("Top Element:  %d\n", value);
                }
                break;
            case 4:
               if(isEmpty()){
                printf("Empty Stack!!");
               }else{
                printf("Populated stack!!");
               }
               break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program!!");
                exit(0);
            default:
                printf("Invalied Choice!! Plz try Again!!");
        }
    }
    return 0;
}