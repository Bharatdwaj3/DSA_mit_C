#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of subarray ranges
long long sumSubarrayRanges(int *arr, int n)
{
    long long totalSum = 0;

    // Loop to find the sum of subarray ranges
    for (int i = 0; i < n; i++)
    {
        int minVal = arr[i], maxVal = arr[i];

        // Loop through all subarrays starting at index i
        for (int j = i; j < n; j++)
        {
            // Update the min and max values for the subarray
            if (arr[j] < minVal)
                minVal = arr[j];
            if (arr[j] > maxVal)
                maxVal = arr[j];

            // Add the range (max - min) of this subarray to the total sum
            totalSum += (maxVal - minVal);
        }
    }

    return totalSum;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sum of subarray ranges: %lld\n", sumSubarrayRanges(arr, n));
    return 0;
}
