#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack
{
    int stack[MAX]; 
    int top;       
};


void push(struct Stack *s)
{
    int value;
    if (s->top < MAX - 1)
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        s->top++;
        s->stack[s->top] = value;
        printf("Pushed %d into stack\n", value);
    }
    else
    {
        printf("Stack is full\n");
    }
}


void pop(struct Stack *s)
{
    if (s->top >= 0)
    {
        printf("Popped %d from stack\n", s->stack[s->top]);
        s->top--;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

void display(struct Stack *s)
{
    if (s->top >= 0)
    {
        printf("Stack: ");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int main()
{
    struct Stack s = {{0}, -1}; 

    push(&s);    
    display(&s);
    pop(&s);     
    display(&s); 

    return 0;
}
