#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 1. Check for Subset
bool isSubset(int A[], int B[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

// 2. Check for Disjoint
bool areDisjoint(int A[], int B[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                return false;
            }
        }
    }
    return true;
}

// 3. Check for Equal
bool areEqual(int A[], int B[], int m, int n)
{
    if (m != n)
        return false;
    for (int i = 0; i < m; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

// 4. Max Distance Between Two Occurrences
int maxDistance(int arr[], int n)
{
    int maxDist = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                maxDist = (j - i > maxDist) ? j - i : maxDist;
            }
        }
    }
    return maxDist;
}

// 5. Duplicate Within K Distance
bool hasDuplicateWithinK(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n && j <= i + k; j++)
        {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

// 6. Intersection of Two Arrays
void intersection(int A[], int B[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                printf("%d ", A[i]);
                break;
            }
        }
    }
}

// 7. Union of Two Arrays
void unionArrays(int A[], int B[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < m; j++)
        {
            if (A[j] == B[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
            printf("%d ", B[i]);
    }
}

// 8. Most Frequent Element
int mostFrequent(int arr[], int n)
{
    int maxCount = 0, mostFreq = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            mostFreq = arr[i];
        }
    }
    return mostFreq;
}

// 9. Maximum Points on the Same Line
int maxPointsOnLine(int points[][2], int n)
{
    int maxCount = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int count = 2;
            for (int k = j + 1; k < n; k++)
            {
                if ((points[j][1] - points[i][1]) * (points[k][0] - points[i][0]) ==
                    (points[k][1] - points[i][1]) * (points[j][0] - points[i][0]))
                {
                    count++;
                }
            }
            maxCount = (count > maxCount) ? count : maxCount;
        }
    }
    return maxCount;
}

// 10. 2 Sum - Find if there is any pair
bool hasPairWithSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
                return true;
        }
    }
    return false;
}

// 11. 2 Sum - Count Pairs
int countPairsWithSum(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
                count++;
        }
    }
    return count;
}

// 12. Count Pairs with Given Diff
int countPairsWithDiff(int arr[], int n, int diff)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == diff)
                count++;
        }
    }
    return count;
}

// 13. Only Repetitive Element from 1 to n-1
int findDuplicate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int absVal = abs(arr[i]);
        if (arr[absVal] < 0)
            return absVal;
        arr[absVal] = -arr[absVal];
    }
    return -1; // No duplicate found
}

// 14. Missing Elements of a Given Range
void missingElements(int arr[], int n, int low, int high)
{
    bool found;
    for (int i = low; i <= high; i++)
    {
        found = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            printf("%d ", i);
    }
}

// 15. Missing Elements from Min to Max of Array
void missingElementsFromMinToMax(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    for (int i = min; i <= max; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            printf("%d ", i);
    }
}

int main()
{
    // Sample Inputs

    int A[] = {11, 1, 13, 21};
    int B[] = {11, 1, 13, 21, 3, 7};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    // Check for Subset
    printf("Check for Subset: %s\n", isSubset(A, B, m, n) ? "Yes" : "No");

    // Check for Disjoint
    printf("Check for Disjoint: %s\n", areDisjoint(A, B, m, n) ? "Yes" : "No");

    // Check for Equal
    printf("Check for Equal: %s\n", areEqual(A, B, m, n) ? "Yes" : "No");

    // Max Distance Between Two Occurrences
    printf("Max Distance Between Two Occurrences: %d\n", maxDistance(A, m));

    // Duplicate Within K Distance
    int arr1[] = {1, 2, 3, 1};
    printf("Duplicate Within K Distance: %s\n", hasDuplicateWithinK(arr1, 4, 3) ? "Yes" : "No");

    // Intersection of Two Arrays
    printf("Intersection of Two Arrays: ");
    intersection(A, B, m, n);
    printf("\n");

    // Union of Two Arrays
    printf("Union of Two Arrays: ");
    unionArrays(A, B, m, n);
    printf("\n");

    // Most Frequent Element
    int arr2[] = {1, 2, 2, 3, 3, 3};
    printf("Most Frequent Element: %d\n", mostFrequent(arr2, 6));

    // 2 Sum - Find if there is any pair
    printf("2 Sum - Find Pair with Sum 22: %s\n", hasPairWithSum(A, m, 22) ? "Yes" : "No");

    // 2 Sum - Count Pairs
    printf("2 Sum - Count Pairs with Sum 22: %d\n", countPairsWithSum(A, m, 22));

    // Count Pairs with Given Diff
    printf("Count Pairs with Diff 1: %d\n", countPairsWithDiff(A, m, 1));

    // Only Repetitive Element from 1 to n-1
    int arr3[] = {1, 2, 3, 2};
    printf("Only Repetitive Element: %d\n", findDuplicate(arr3, 4));

    // Missing Elements from Min to Max of Array
    printf("Missing Elements from Min to Max of Array: ");
    missingElementsFromMinToMax(arr3, 4);
    printf("\n");

    return 0;
}
