#include <stdio.h>
#include <stdlib.h>

void nextSmallerElement(int arr[], int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        while (top >= 0 && arr[stack[top]] > arr[i])
        {
            printf("%d -> %d\n", arr[stack[top]], arr[i]);
            top--;
        }
        stack[++top] = i;
    }

    while (top >= 0)
    {
        printf("%d -> -1\n", arr[stack[top]]);
        top--;
    }

    free(stack);
}

int main()
{
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextSmallerElement(arr, n);
    return 0;
}
