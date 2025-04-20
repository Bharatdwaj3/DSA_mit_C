```c

struct Node *findMiddle(struct Node *head){
    struct Node*slow=head,*fast=head;
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
        if(slow=fast){
            return 1;
        }
    }
    return 0;
}

int hasLoop(struct Node*head){
    struct Node*slow=head,*fast=head;
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

int hasLoop(struct Node*head){
    struct Node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
           int length=1;
           struct NOde*temp=slow->next;
           while(temp!=slow){
            temp=temp->next;
            length++
           }
           return length;
        }
    }
    return 0;
}
```