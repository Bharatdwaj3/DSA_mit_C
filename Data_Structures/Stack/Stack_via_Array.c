#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void push(int stack[], int *top)
{
    int value;
    if (*top == MAX - 1)
    {
        printf("\nStack is full!\n");
        return;
    }
    printf("Enter the value you wanna push: ");
    scanf("%d", &value);
    stack[++(*top)] = value;
    printf("\nPushed %d into the stack!!\n", stack[*top]);
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nPopped from the stack: %d\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nTop element: %d\n", stack[top]);
    }
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack contents:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int stack[MAX], top = -1;
    int choice;

    while (1)
    {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            peek(stack, top);
            break;
        case 4:
            display(stack, top);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}
