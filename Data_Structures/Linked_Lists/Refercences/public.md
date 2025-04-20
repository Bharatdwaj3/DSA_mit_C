# Java

```java

    public void insertAtEnd(int value){
        Node newNode=new Node(value);
        if(head==null){
            head=newNode;
        }else{
            Node temp=head;
            while(temp.next!=null){
                temp=temp.next;
            }
            temp.next=newNode;
        }
    }
```
