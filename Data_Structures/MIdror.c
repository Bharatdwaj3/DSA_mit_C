#include<stdio.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void insertAtStart(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the start of the list",value);
}

void printList(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct Node*reverseListItervative(struct Node*head){
    struct Node*prev=NULL, *current=head, *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
    }
}

int hasLoop(){
    struct Node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}
int findLoopStart(){
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
           slow=head;
           while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
           }
           return slow;
        }
        return NULL;
    }
}

int lengthOfLoop(struct Node*head){
    struct Node*slow=head,*fast=head;
    while(fast!=head&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int length=1;
            struct Node*temp=slow->next;
            while(temp!=slow){
                temp=temp->next;
                length++;
            }
            return length;
        }
    }
    return 0;
}
void deleteFromMittle(){
    if(head==NULL||head->next==NULL){
        return;
    }
    struct Node *slow=head,*fast=head,*prev=NULL;
    while(fast!=NULL&&fast!=NULL){
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=slow->next;
    free(slow);
}

int main(){

}