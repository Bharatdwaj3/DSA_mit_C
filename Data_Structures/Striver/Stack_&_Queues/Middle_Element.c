#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack
{
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

// Function to push an element onto the stack
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->arr[++ptr->top] = val;
    }
}

// Function to pop an element from the stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1; // Error value
    }
    else
    {
        return ptr->arr[ptr->top--];
    }
}

// Function to find the middle element of the stack
int findMiddle(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return -1;
    }
    int midIndex = ptr->top / 2;
    return ptr->arr[midIndex];
}

// Main function
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // Pushing elements into the stack
    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    push(sp, 50);

    // Finding and printing the middle element
    printf("Middle element in the stack: %d\n", findMiddle(sp));

    // Free allocated memory
    free(sp->arr);
    free(sp);

    return 0;
}
