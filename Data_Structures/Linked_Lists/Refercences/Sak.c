#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node*head =NULL;

void insertAtBegining(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    head=newNode;
    printf("Inserted %d at the begining of the list\n",value);
}

void insertAtBegining(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        struct Node*temp=NULL;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d at the end of the list\n", value);
}

void deleteAtBegining() {
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("Deleted %d from the begining of the list\n",temp->data);
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is Empty!!");
        return;
    }
    if(head->next==NULL){
        printf("Dleted %d from the end of the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head;
    while(temp=temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Dleted %d from the end of the list\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}

void peek(){
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    printf("Front element: %d\n",head->data);
    
}

void displayList(){
    if (head == NULL){
        printf("List is empty!!");
        return;
    }
    struct Node*temp;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d->",head->data);
        temp=temp->next;
    }
    printf('\n');
}

int main(){
    insertAtBegining(10);
    insertAtBegining(20);
    insertAtBegining(30);
    displayList();

    insertAtEnd(100);
    insertAtEnd(200);
    insertAtEnd(300);
    displayList();

    deleteAtBegining();
    displayList();

    deleteAtEnd();
    displayList();

    peek();
}