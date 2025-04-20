#include<stdlib.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void printList(){
    if(head==NULL){
        printf("\nEmpty");
        return;
    }
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insertAtStart(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node*));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Inserted %d in the start of the list",value);
}
void insertAtEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = value;
    newNode->next = NULL;
   
   if(head==NULL){
       head = newNode;
   }else{
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
   }
    printf("Inserted %d in the start of the list", value);
}
void deleteAtStart(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("The Node %d is deleted from the start!!",temp->data);
    free(temp);
    temp=NULL;
}

void deleteAtEnd()
{
  if(head==NULL){
    printf("Empty!!");
    return;
  }
   if(head->next==NULL){
    printf("Value %d is deleted from the end!!",head->data);
    free(head);
    head=NULL;
    return;
   }
   struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
    printf("Deleted %d in the end of the list", temp->data);
    free(temp->next);
    temp->next=NULL;
}

int main(){

}