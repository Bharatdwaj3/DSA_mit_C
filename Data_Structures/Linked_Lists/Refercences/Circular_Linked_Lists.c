#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself if it's the only node
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode; 
    }
    printf("Inserted %d at the beginning of the list.\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode; // Circular link
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head) // Find last node
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Make it circular
    }
    printf("Inserted %d at the end of the list.\n", value);
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted %d from the list.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *last = head;
    while (last->next != head) // Find last node
    {
        last = last->next;
    }
    head = head->next; // Move head
    last->next = head; // Maintain circular link
    printf("Deleted %d from the beginning of the list.\n", temp->data);
    free(temp);
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted %d from the list.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head; // Maintain circular link
    printf("Deleted %d from the end of the list.\n", temp->data);
    free(temp);
}

void peek()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
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
        printf("7. Exit\n");
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
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}
