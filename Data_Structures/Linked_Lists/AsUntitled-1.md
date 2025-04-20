```C
 temp->next = newNode;
        newNode->next = head;//won't this create a new node at end ??
        head = newNode; 
```