#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* head = NULL;
// Initialize the linked list
 Node* initialize(int data)
 {
     Node* newNode = (Node*)malloc(sizeof(Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;

 }
 // Insert at the specfic position
  Node* insertSpecfic( int data, int position)
  {
      Node* newNode = initialize(data);
      if(head==NULL )
      {
          head = newNode ;
          return head;
      }
      if(position==1)
      {
          newNode->next = head;
          head = newNode;
          return head;
      }
      Node* current = head;
       int runner = 0;
       while(current!=NULL && runner<position-2)
       {
           current = current->next;
           runner++;
       }
       if(current==NULL)
       {
           printf("Position out of Bound\n");
           return head;
       }
       newNode->next=current->next;
       current->next = newNode;
       return head;

  }
  void printList()
  {
      if(head==NULL)
      {
          return;
      }
      Node* current = head;
      while(current!=NULL)
      {
        printf("%d->",current->data);
        current= current->next;
      }
      printf("NULL\n");
  }
  void printListAlternate()
  {
      if(head==NULL)
      {
          return;
      }
      Node* current = head;
      while(current!=NULL)
      {
        printf("%d->",current->data);
        if(current->next==NULL){
            break;
        }
        current= current->next->next;
      }
      printf("NULL\n");
  }
// Delete the Node by value
void deleteByValue(int value)
{
    

}


int main()
{
    insertSpecfic(1,3);
    insertSpecfic(2,1);
    insertSpecfic(3,2);
    insertSpecfic(4,3);
    insertSpecfic(8,3);
    printList();
    printListAlternate();

    return 0;
}