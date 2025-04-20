#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

void push(Stack *stack, int element)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow! Cannot push element %d\n", element);
        return;
    }
    stack->arr[++stack->top] = element;
    printf("Pushed %d onto the stack.\n", element);
}

int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    initialize(&stack);
    int choice, value;

    do
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
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1)
                printf("Popped element: %d\n", value);
            break;
        case 3:
            value = peek(&stack);
            if (value != -1)
                printf("Top element: %d\n", value);
            break;
        case 4:
            display(&stack);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
