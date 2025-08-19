#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};

struct Node *toCircular(struct Node*head){
    if(!head)
        return NULL;
    struct Node*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    return head;
}

int count_Occur(struct Node*head, int value){
    int count=0;
    while(head!=NULL){
        if(head->data==value){
            count++;
        }
        return count;
    }
}

int isCircular(struct Node*head){
    if(!head)
        return 1;
    struct Node* temp=head->next;
    while(temp !=NULL &&temp!=head){
        temp=temp->next;
    }
    return temp==head;
}

struct Node* rev_S(struct Node*head){
    struct Node*prev=NULL, *curr=head, *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
}

struct Node* findPairs(struct Node*head, int target){
    struct Node* curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        int sum=curr->data+curr->next->data;
        if(sum==target){
            printf("Pair found: (%d, %d)\n",curr->data, curr->next->data);
        }
        curr=curr->next;
    }
}

struct Node* swapPairs(struct Node* head){
    if(head==NULL || head->next==NULL)
        return NULL;
    struct Node* newHead=head->next, *prev=NULL,*curr=NULL;
    while(curr!=NULL&&curr->next!=NULL){
        struct Node* nextPair=curr->next->next;
        struct Node* second=curr->next;
                    second->next=curr;
                    curr->next=nextPair;
        if(prev!=NULL)
            prev->next=second;
        prev=curr;
        curr=nextPair;
    } 
    return newHead;
}

struct Node* swapPairsmitSum(struct Node*head, int target){
    if(head==NULL||head->next==NULL)
        return head;
    struct Node*temp=malloc(sizeof(struct Node));
    temp->next=head;
    struct Node*prev=temp;
    struct Node*curr=head;
    while(curr!=NULL && curr->next!=NULL){
        struct Node*first=curr;
        struct Node*second=curr->next;
        struct Node*nextPair=second->next;
        if((first->data+second->data)==target){
            second->next=first;
            first->next=nextPair;
            prev->next=second;

            prev=first;
            curr=nextPair;
        }else{
            prev=curr;
            curr=curr->next;
        }
    }
    struct NOde* newHead=temp->next;
    free(temp);
    return newHead;

}

struct Node* rotateDList(struct Node*head, int value){
    if(head==NULL||value==0)
        return head;
    struct Node* tail=head;
    int count=1;
    while(count<value&&tail!=NULL){
        tail=tail->next;
        count++;
    }
    if(tail==NULL||tail->next==NULL)
        return head;
    struct Node* newNode=tail->next;
    newNode->prev=NULL;
    tail->next=NULL;
    struct Node*end=newNode;
    while(end->next!=NULL){
        end=end->next;
    }
    end->next=head;
    head->prev=end;
    return newNode;
}

struct Node* rev_S(struct Node*head){
    struct Node *curr=head, *temp=NULL;{
        while(curr!=NULL){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        if(temp!=NULL){
            head=head->prev;
            return head;
        }
    }
}

struct Node *findMiddle(struct Node *head){
    struct Node*slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


int hasLoop(struct Node*head){
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

struct Node *findLoopStart(struct Node *head){
    struct Node *slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

void removeNthFromEnd(struct Node *head, int n){
    struct Node *fast=head, *slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        head=head->next;
        return;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }   
    slow->next=slow->next->next;
}

struct Node* deleteGivenNode(struct Node*node){
    if(node==NULL||node->next==NULL){
        return node;
    }
    struct Node*temp=node->next;
    node->data=temp->data;
    node->next=temp->next;
    free(temp);
    return node;
}