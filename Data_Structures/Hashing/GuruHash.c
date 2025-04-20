#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// Represent Fraction as String
char *fractionToString(int numerator, int denominator)
{
    if (denominator == 0)
        return "Undefined";
    static char result[50];
    sprintf(result, "%d/%d", numerator, denominator);
    return result;
}

// 4 Sum – Count quadruplets
int fourSumCount(int *A, int *B, int *C, int *D, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (A[i] + B[j] + C[k] + D[l] == 0)
                        count++;
                }
            }
        }
    }
    return count;
}

// Largest subarray with equal number of 0s and 1s
int maxLen(int arr[], int n)
{
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += (arr[j] == 0) ? -1 : 1;
            if (sum == 0)
                max_length = (j - i + 1 > max_length) ? (j - i + 1) : max_length;
        }
    }
    return max_length;
}

// Recaman’s sequence
void recaman(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    bool *visited = (bool *)calloc(n, sizeof(bool));
    arr[0] = 0;
    visited[0] = true;
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i - 1] - i;
        if (cur > 0 && !visited[cur])
            arr[i] = cur;
        else
            arr[i] = arr[i - 1] + i;
        visited[arr[i]] = true;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    free(visited);
}

int main()
{
    // Fraction Representation
    printf("Fraction: %s\n", fractionToString(3, 7));

    // Recaman's Sequence
    printf("Recaman’s Sequence: ");
    recaman(10);

    // Largest subarray with equal number of 0s and 1s
    int arr[] = {1, 0, 1, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Largest subarray with equal 0s and 1s: %d\n", maxLen(arr, n));

    return 0;
}
