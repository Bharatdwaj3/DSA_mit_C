#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head; // Insert at beginning (prepend)
    head = newNode;
    printf("Inserted %d at the beginning of the list\n", value);
}

void revList()
{
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev; // ✅ Update head to the new first node
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertNode(11);
    insertNode(12);
    insertNode(13);
    display();

    revList();
    printf("Reversed list:\n");
    display();

    return 0;
}
