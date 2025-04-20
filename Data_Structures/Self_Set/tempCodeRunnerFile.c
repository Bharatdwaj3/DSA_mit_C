#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void push(int stack[], int *top)
{
    int value;
    printf("Enter the value you wanna push: ");
    while (*top < MAX - 1)
    {
        scanf("%d", &value);
        stack[++(*top)] = value;
        printf("\nPushed %d into the stack!!\n", stack[*top]);
        if (*top == MAX - 1)
        {
            printf("\nStack is full!\n");
            break;
        }
    }
}

void pop(int stack[], int *top)
{
    printf("\nPop from stack!!\n");
    if (*top == -1)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nPopped from the stack %d\n", stack[*top]);
        (*top)--; 
    }
}


void display(int stack[], int top)
{
    printf("\nThe stack displayed!!\n");
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("\nStack: %d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int stack[MAX], top = -1;

    push(stack, &top);
    display(stack, top);
    pop(stack, &top);
    display(stack, top);

    return 0;
}
