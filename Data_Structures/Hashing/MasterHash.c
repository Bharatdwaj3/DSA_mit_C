#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

// Function to check if arr1 is a subset of arr2
bool isSubset(int arr1[], int n1, int arr2[], int n2)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n2; i++)
        hash[arr2[i]] = 1;
    for (int i = 0; i < n1; i++)
        if (!hash[arr1[i]])
            return false;
    return true;
}

// Function to check if two arrays are disjoint
bool isDisjoint(int arr1[], int n1, int arr2[], int n2)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n1; i++)
        hash[arr1[i]] = 1;
    for (int i = 0; i < n2; i++)
        if (hash[arr2[i]])
            return false;
    return true;
}

// Function to check if two arrays are equal
bool areEqual(int arr1[], int n1, int arr2[], int n2)
{
    if (n1 != n2)
        return false;
    int hash[MAX] = {0};
    for (int i = 0; i < n1; i++)
        hash[arr1[i]]++;
    for (int i = 0; i < n2; i++)
        if (--hash[arr2[i]] < 0)
            return false;
    return true;
}

// Max distance between two occurrences of same element
int maxDistance(int arr[], int n)
{
    int hash[MAX];
    memset(hash, -1, sizeof(hash));
    int maxDist = 0;
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == -1)
            hash[arr[i]] = i;
        else
            maxDist = (i - hash[arr[i]] > maxDist) ? i - hash[arr[i]] : maxDist;
    }
    return maxDist;
}

// Duplicate within K distance
bool duplicateWithinK(int arr[], int n, int k)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] && (i - hash[arr[i]] <= k))
            return true;
        hash[arr[i]] = i;
    }
    return false;
}

// Intersection of Two Arrays
void intersection(int arr1[], int n1, int arr2[], int n2)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n1; i++)
        hash[arr1[i]] = 1;
    for (int i = 0; i < n2; i++)
        if (hash[arr2[i]])
            printf("%d ", arr2[i]);
}

// Union of Two Arrays
void unionArrays(int arr1[], int n1, int arr2[], int n2)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n1; i++)
        hash[arr1[i]] = 1;
    for (int i = 0; i < n2; i++)
        hash[arr2[i]] = 1;
    for (int i = 0; i < MAX; i++)
        if (hash[i])
            printf("%d ", i);
}

// Most Frequent Element
int mostFrequent(int arr[], int n)
{
    int hash[MAX] = {0}, maxCount = 0, maxElement = -1;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
        if (hash[arr[i]] > maxCount)
        {
            maxCount = hash[arr[i]];
            maxElement = arr[i];
        }
    }
    return maxElement;
}

// 2 Sum - Find if there is any pair
bool twoSumExists(int arr[], int n, int target)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        if (hash[target - arr[i]])
            return true;
        hash[arr[i]] = 1;
    }
    return false;
}

// 2 Sum - Count Pairs
int countPairs(int arr[], int n, int target)
{
    int hash[MAX] = {0}, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (hash[target - arr[i]])
            count++;
        hash[arr[i]] = 1;
    }
    return count;
}

// Count Pairs with Given Diff
int countPairsWithDiff(int arr[], int n, int diff)
{
    int hash[MAX] = {0}, count = 0;
    for (int i = 0; i < n; i++)
        hash[arr[i]] = 1;
    for (int i = 0; i < n; i++)
        if (hash[arr[i] + diff])
            count++;
    return count;
}

// Only repetitive element from 1 to n-1
int findRepetitive(int arr[], int n)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]])
            return arr[i];
        hash[arr[i]] = 1;
    }
    return -1;
}

// Missing elements of a range
void missingElements(int arr[], int n, int range)
{
    int hash[MAX] = {0};
    for (int i = 0; i < n; i++)
        hash[arr[i]] = 1;
    for (int i = 1; i <= range; i++)
        if (!hash[i])
            printf("%d ", i);
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Is Subset: %s\n", isSubset(arr1, n1, arr2, n2) ? "Yes" : "No");
    printf("Is Disjoint: %s\n", isDisjoint(arr1, n1, arr2, n2) ? "Yes" : "No");
    printf("Are Equal: %s\n", areEqual(arr1, n1, arr2, n2) ? "Yes" : "No");

    printf("Intersection: ");
    intersection(arr1, n1, arr2, n2);
    printf("\n");

    printf("Union: ");
    unionArrays(arr1, n1, arr2, n2);
    printf("\n");

    return 0;
}
