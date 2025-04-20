#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void insertAtBegining(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted %d at the beginning of the list\n",value);
}

void insertAtEnd(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
    }else{
        struct Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    printf("Inserted %d at the end of the list\n",value);
}

void deleteFromBeginning (){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head,*last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("Deleted %d from the beginning of trhe list\n",temp->data);
    free(temp);
}

void deleteFromEnd(){
    if(head==NULL){
        printf("Empty!!");
        return; 
    }
    if(head->next==head){
        printf("Deleted %d from the list\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node*temp=head,*prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    printf("Deleted %d from the end of the list\n",temp->data);
    free(temp);
}

void peek(){
    if(head==NULL){
        printf("Empty!!");
        return;
    }
    printf("Front element : %d",head->data);
}

void displayList(){
    if(head==NULL){
        printf("Empty List\n");
        return;
    }
    struct Node*temp=head;
    printf("Circular Linked List!!");
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("(head)\n");
}


int getLength(){
    if(head==NULL)
        return 0;
    int count=0;
    struct Node *temp=head;
    do{
        count++; 
        temp=temp->next;
    }while(temp!=head);
    return count;
}

int isCircular(){
    if(head==NULL) return 0;
    struct Node*temp=head;
    while(temp->next!=NULL&&temp->next!=head){
        temp=temp->next;
    }
    return (temp->next==head);
}

struct NOde* search(int value){
    if(head==NULL) return head;
    struct Node*temp=head;
    do{
        if(temp->data==value) return temp;
        temp=temp->next;
    }while(temp!=head);
    return NULL;
}

void splitCircularLinkedList(struct Node** head1, struct Node**head2){
    if(head==NULL||head->next==head)
    return;
    struct Node*slow=head, *fast=head;
    while(fast->next!=head&&fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1=head;
    *head2=slow->next;
    slow->next=*head1;
    struct Node*temp=*head2;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=*head2;
}

void mergeCircularLinkedLists(struct  Node* head1, struct Node *head2){
    if(head1==NULL){
        head=head2;
        return;
    }
    if(head2==NULL)return;
    struct Node*temp=head1;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head2;
    temp=head2;
    while(temp->next!=head2){
        temp=temp->next;
    }
    temp->next=head1;
    head=head1;
}

void sortCircularLinkedList(){
    if(head==NULL) return;
    struct Node*temp1=head, *temp2;
    int swapped;
    do{
        swapped = 0;
        temp2=head;
        while(temp2->next!=head){
            if(temp2->data>temp2->next->data){
                int temp=temp2->data;
                temp2->data=temp2->next->data;
                temp2->next->data=temp;
                swapped =1;
            }
            temp2=temp2->next;
        }
    } while (swapped);
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Peek\n");
        printf("6. Display List\n");
        printf("7. getLength\n");
        printf("8. IsCirclua\n");
        printf("9. Split List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            deleteFromBeginning();
            break;
        case 4:
            deleteFromEnd();
            break;
        case 5:
            peek();
            break;
        case 6:
            displayList();
            break;
        case 7:
            getLength();
            break;
        case 8:
            isCircular();
            break;
        case 9:
            struct Node *head1 = NULL, *head2 = NULL;
            splitCircularLinkedList(&head1,&head2);
            break;
        case 10:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}
