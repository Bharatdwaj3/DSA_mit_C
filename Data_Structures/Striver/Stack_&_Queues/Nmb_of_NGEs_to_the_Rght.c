#include <stdio.h>
#include <stdlib.h>

void countNextGreaterElements(int arr[], int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int *result = (int *)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        while (top >= 0 && arr[stack[top]] < arr[i])
        {
            result[stack[top]]++;
            top--;
        }
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Element %d has %d NGE(s)\n", arr[i], result[i]);
    }

    free(stack);
    free(result);
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    countNextGreaterElements(arr, n);
    return 0;
}
