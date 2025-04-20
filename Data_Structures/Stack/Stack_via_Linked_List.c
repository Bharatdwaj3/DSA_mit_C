#include <stdio.h>
#include <stdlib.h>

// Node structure to represent each element in the stack
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL; // Initialize the stack as an empty linked list

// Push an element onto the stack
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack\n", value);
}

// Pop an element from the stack
int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node *temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Peek at the top element without removing it
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Check if the stack is empty
int isEmpty()
{
    return top == NULL;
}

// Display the elements in the stack
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Node *temp = top;
        printf("Stack: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped: %d\n", value);
            }
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("Top element: %d\n", value);
            }
            break;
        case 4:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
