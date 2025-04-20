#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement2(int arr[], int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < 2 * n; i++)
    {
        while (top >= 0 && arr[stack[top]] < arr[i % n])
        {
            printf("%d -> %d\n", arr[stack[top]], arr[i % n]);
            top--;
        }
        stack[++top] = i % n;
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
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreaterElement2(arr, n);
    return 0;
}
