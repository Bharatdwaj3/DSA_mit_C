#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if array pair sums are divisible by k
bool checkPairSumsDivisible(int arr[], int n, int k)
{
    int remainder[k];
    memset(remainder, 0, sizeof(remainder));

    for (int i = 0; i < n; i++)
        remainder[arr[i] % k]++;

    if (remainder[0] % 2 != 0)
        return false;

    for (int i = 1; i < k; i++)
    {
        if (remainder[i] != remainder[k - i])
            return false;
    }
    return true;
}

// Function to find the longest subarray with sum divisible by k
int longestSubarrayDivisibleByK(int arr[], int n, int k)
{
    int sum = 0, maxLen = 0;
    int modIndex[k];
    memset(modIndex, -1, sizeof(modIndex));

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int mod = ((sum % k) + k) % k;
        if (mod == 0)
            maxLen = i + 1;
        else if (modIndex[mod] == -1)
            modIndex[mod] = i;
        else
            maxLen = (i - modIndex[mod]) > maxLen ? (i - modIndex[mod]) : maxLen;
    }
    return maxLen;
}

// Function to count triplets with a given sum
int countTriplets(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                    count++;
            }
        }
    }
    return count;
}

// Function to find all triplets with zero sum
void findZeroSumTriplets(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                    printf("(%d, %d, %d)\n", arr[i], arr[j], arr[k]);
            }
        }
    }
}

// Function to find itinerary from a given list of tickets
void findItinerary(char tickets[][2][20], int n)
{
    // Implementation will use hash maps which is complex in basic C
    printf("Not implemented in basic C");
}

// Function to find the largest subarray with sum 0
int largestSubarrayWithZeroSum(int arr[], int n)
{
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
                maxLen = (j - i + 1) > maxLen ? (j - i + 1) : maxLen;
        }
    }
    return maxLen;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Pairs divisible by %d: %s\n", k, checkPairSumsDivisible(arr, n, k) ? "Yes" : "No");
    printf("Longest subarray with sum divisible by %d: %d\n", k, longestSubarrayDivisibleByK(arr, n, k));
    printf("Triplets with sum %d: %d\n", k, countTriplets(arr, n, k));
    printf("Triplets with zero sum:\n");
    findZeroSumTriplets(arr, n);
    printf("Largest subarray with 0 sum: %d\n", largestSubarrayWithZeroSum(arr, n));

    return 0;
}
