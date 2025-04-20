#include <stdio.h>
#include <stdlib.h>

void nextSmallerElement(int *arr, int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int *result = (int *)malloc(n * sizeof(int));
    int top = -1;

    // Initialize result array with -1 (default value when no smaller element exists)
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Pop elements from stack while the current element is smaller than stack's top element
        while (top >= 0 && arr[stack[top]] > arr[i])
        {
            result[stack[top]] = arr[i]; // Update the result array
            top--;                       // Pop the element from the stack
        }

        // Push the current index to the stack
        stack[++top] = i;
    }

    // Print the result array (Next Smaller Element for each index)
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(stack);
    free(result);
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextSmallerElement(arr, n);
    return 0;
}
