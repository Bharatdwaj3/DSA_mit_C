#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Global head and tail pointers
struct Node *head = NULL;
struct Node *tail = NULL;

// Insert at the beginning
void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    else
    {
        tail = newNode;
    }

    head = newNode;
    printf("Inserted %d at the beginning of the list.\n", value);
}

// Insert at the end
void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }

    tail = newNode;
    printf("Inserted %d at the end of the list.\n", value);
}

// Delete from the beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }

    printf("Deleted %d from the beginning of the list.\n", temp->data);
    free(temp);
}

// Delete from the end
void deleteFromEnd()
{
    if (tail == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
    {
        tail->next = NULL;
    }
    else
    {
        head = NULL;
    }

    printf("Deleted %d from the end of the list.\n", temp->data);
    free(temp);
}

// Display forward
void displayForward()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display backward
void displayBackward()
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = tail;
    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Peek (show front and back)
void peek()
{
    if (head == NULL || tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Front: %d, Back: %d\n", head->data, tail->data);
}

// Main function with menu
int main()
{
    int choice, value;
    while (1)
    {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Peek\n");
        printf("6. Display Forward\n");
        printf("7. Display Backward\n");
        printf("8. Exit\n");
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
            displayForward();
            break;
        case 7:
            displayBackward();
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
