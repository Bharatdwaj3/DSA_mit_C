#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initially the stack is empty

int main()
{
    // Push elements onto the stack
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = 10;
        printf("10 pushed onto stack\n");
    }

    if (top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = 20;
        printf("20 pushed onto stack\n");
    }

    if (top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = 30;
        printf("30 pushed onto stack\n");
    }

    // Display the elements in the stack
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    // Pop an element from the stack
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped: %d\n", stack[top--]);
    }

    // Display the elements again after pop
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
