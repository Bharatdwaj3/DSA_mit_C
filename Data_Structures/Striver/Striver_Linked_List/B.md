```java
    public void(head){
        Node slow=new Node(head);
        Node fast=new Node(head);
        while(slow!=null&&fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return;
    }
```