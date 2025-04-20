#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
    int stack[MAX], i, value;
    int top = -1;

    printf("Enter the value you wanna push: ");
    while (top < MAX - 1)
    {
        
        scanf("%d", &value);  
        stack[++top] = value;
    }

   
    printf("\nThe stack displayed!!\n");
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("\nStack: %d ", stack[i]);
        }
    }

   
    printf("\nPop from stack!!\n");
    if (top == -1)
    {
        printf("\nStack is empty!!\n");
    }
    else
    {
        printf("\nPopped from the stack %d: \n", stack[top]);
        top--; 
    }

    printf("\nThe stack displayed!!\n");
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("\nStack: %d ", stack[i]);
        }
    }

    return 0;
}
