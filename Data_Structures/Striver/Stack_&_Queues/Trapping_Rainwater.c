#include <stdio.h>
#include <stdlib.h>

int trap(int arr[], int n)
{
    int *leftMax = (int *)malloc(n * sizeof(int));
    int *rightMax = (int *)malloc(n * sizeof(int));
    int waterTrapped = 0;

    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = (arr[i] > leftMax[i - 1]) ? arr[i] : leftMax[i - 1];
    }

    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = (arr[i] > rightMax[i + 1]) ? arr[i] : rightMax[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        waterTrapped += (leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i]) - arr[i];
    }

    free(leftMax);
    free(rightMax);

    return waterTrapped;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Total trapped water: %d\n", trap(arr, n));
    return 0;
}
