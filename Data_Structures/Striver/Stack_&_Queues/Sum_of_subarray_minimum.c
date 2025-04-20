#include <stdio.h>
#include <stdlib.h>

int sumOfSubarrayMinimum(int arr[], int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    long long sum = 0;
    int mod = 1e9 + 7;
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        while (top >= 0 && arr[stack[top]] >= arr[i])
        {
            top--;
        }

        if (top == -1)
        {
            sum += (i + 1) * arr[i];
        }
        else
        {
            sum += (i - stack[top]) * arr[i];
        }

        sum %= mod;
        stack[++top] = i;
    }

    free(stack);
    return sum;
}

int main()
{
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of subarray minimums: %d\n", sumOfSubarrayMinimum(arr, n));
    return 0;
}
