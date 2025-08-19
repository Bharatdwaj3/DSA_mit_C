#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 1. Check If Array Pair Sums Divisible by k
bool checkPairSumDivisibleByK(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) % k == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// 2. Longest Subarray with Sum Divisible by k
int longestSubarrayWithSumDivisibleByK(int arr[], int n, int k)
{
    int maxLength = 0;
    int sum = 0;
    int hashMap[1000];
    memset(hashMap, -1, sizeof(hashMap));

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int mod = sum % k;

        if (mod < 0)
            mod += k; // Handle negative mod values

        if (mod == 0)
        {
            maxLength = i + 1;
        }
        else
        {
            if (hashMap[mod] == -1)
            {
                hashMap[mod] = i;
            }
            else
            {
                maxLength = (i - hashMap[mod] > maxLength) ? i - hashMap[mod] : maxLength;
            }
        }
    }
    return maxLength;
}

// 3. 3 Sum - Count All Triplets with Given Sum
int countTripletsWithGivenSum(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

// 4. 3 Sum – Find All Triplets with Zero Sum
void findTripletsWithZeroSum(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    printf("Triplet: (%d, %d, %d)\n", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}

// 5. Itinerary from a Given List of Tickets (Find Eulerian Path)
void printItinerary(char tickets[][2][50], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s -> %s\n", tickets[i][0], tickets[i][1]);
    }
}

// 6. Longest Subarray Having Majority Elements Greater Than K
int longestSubarrayWithMajorityElementsGreaterThanK(int arr[], int n, int k)
{
    int maxLength = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            count++;
        }
        if (count > maxLength)
        {
            maxLength = count;
        }
        if (arr[i] <= k)
        {
            count = 0;
        }
    }
    return maxLength;
}

// 7. Number of Employees Under Every Employee (Tree structure with parent-child relations)
void printEmployeesUnderEach(int n, int manager[], int emp)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (manager[i] == emp)
        {
            count++;
        }
    }
    printf("Number of employees under %d: %d\n", emp, count);
}

// 8. Largest Subarray with 0 Sum
int largestSubarrayWithZeroSum(int arr[], int n)
{
    int maxLength = 0;
    int sum = 0;
    int hashMap[1000];
    memset(hashMap, -1, sizeof(hashMap));

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLength = i + 1;
        }
        else
        {
            int mod = sum % 1000;
            if (hashMap[mod] == -1)
            {
                hashMap[mod] = i;
            }
            else
            {
                maxLength = (i - hashMap[mod] > maxLength) ? i - hashMap[mod] : maxLength;
            }
        }
    }
    return maxLength;
}

// 9. Subarray with Given Sum
bool subarrayWithGivenSum(int arr[], int n, int sum)
{
    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_sum = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (current_sum == sum)
            {
                return true;
            }
            current_sum += arr[j];
        }
    }
    return false;
}

// 10. Longest Consecutive Subsequence
int longestConsecutiveSubsequence(int arr[], int n)
{
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int currentLength = 1;
        int currentNum = arr[i];

        while (currentNum + 1 == arr[i + 1])
        {
            currentLength++;
            currentNum++;
        }
        maxLength = (currentLength > maxLength) ? currentLength : maxLength;
    }
    return maxLength;
}

// 11. Largest Fibonacci Subset
int largestFibonacciSubset(int arr[], int n)
{
    // Implementation left for future
    return -1;
}

// 12. Consecutive Subset Partitioning
int partitionConsecutiveSubset(int arr[], int n)
{
    // Implementation left for future
    return -1;
}

// 13. Distincts in Every Window of Size k
void distinctsInEveryWindowOfSizeK(int arr[], int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int count = 0;
        for (int j = i; j < i + k; j++)
        {
            bool found = false;
            for (int l = i; l < j; l++)
            {
                if (arr[j] == arr[l])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                count++;
            }
        }
        printf("Distinct elements in window [%d, %d]: %d\n", i, i + k - 1, count);
    }
}

// 14. Insert, Delete, Search, and GetRandom (for Randomized Set)
struct RandomizedSet
{
    int *nums;
    int size;
    struct RandomizedSet *next;
};
void insert(struct RandomizedSet *set, int val)
{
    // insert val logic here
}

// 15. Min Insertions for Palindrome Permutation
int minInsertionsForPalindromePermutation(char *str)
{
    // Implementation left for future
    return -1;
}

// 16. Maximum Possible Difference of Two Subsets of an Array
int maxPossibleDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int maxDiff = sum;
    return maxDiff;
}

// 17. Sorting Using Trivial Hash Function
void sortUsingTrivialHashFunction(int arr[], int n)
{
    // Implementation of trivial hash sorting
}

// 18. Smallest Subarray with k Distinct Numbers
int smallestSubarrayWithKDistinctNumbers(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // Check logic for distinct numbers
    }
    return count;
}

// 19. All Pairs (a, b) in an Array Such That a % b = k
void findPairsWithModuloK(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] % arr[j] == k)
            {
                printf("Pair: (%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

// 20. Group Words with Same Set of Characters
void groupWordsWithSameSetOfCharacters(char words[][50], int n)
{
    // Implementation left for future
}

// 21. k-th Distinct Element in an Array
int kthDistinctElement(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            count++;
            if (count == k)
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int main()
{
    // Test data
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;          // For checking pair sum divisibility by k
    int sum = 6;        // For counting triplets with a given sum
    int target_sum = 0; // For finding triplets with zero sum

    // Check Pair Sum Divisible by k
    printf("Check Pair Sum Divisible by %d: %s\n", k, checkPairSumDivisibleByK(arr, n, k) ? "Yes" : "No");

    // Longest Subarray with Sum Divisible by k
    printf("Longest Subarray with Sum Divisible by %d: %d\n", k, longestSubarrayWithSumDivisibleByK(arr, n, k));

    // 3 Sum - Count All Triplets with Given Sum
    printf("3 Sum - Count All Triplets with Given Sum (%d): %d\n", sum, countTripletsWithGivenSum(arr, n, sum));

    // 3 Sum – Find All Triplets with Zero Sum
    printf("3 Sum – Find All Triplets with Zero Sum:\n");
    findTripletsWithZeroSum(arr, n);

    // Itinerary from a Given List of Tickets (example)
    char tickets[3][2][50] = {
        {{"A", "B"}, {"B", "C"}},
        {{"B", "C"}, {"C", "D"}},
        {{"C", "D"}, {"D", "A"}}};
    printf("Itinerary:\n");
    printItinerary(tickets, 3);

    // Longest Subarray Having Majority Elements Greater Than k
    printf("Longest Subarray Having Majority Elements Greater Than %d: %d\n", k, longestSubarrayWithMajorityElementsGreaterThanK(arr, n, k));

    // Number of Employees Under Every Employee
    int manager[] = {0, 1, 1, 2, 2}; // Manager array example (tree structure)
    printf("Number of Employees under Employee 2: ");
    printEmployeesUnderEach(n, manager, 2);

    // Largest Subarray with 0 Sum
    printf("Largest Subarray with 0 Sum: %d\n", largestSubarrayWithZeroSum(arr, n));

    // Subarray with Given Sum
    int given_sum = 9; // Example for subarray sum
    printf("Subarray with Given Sum %d: %s\n", given_sum, subarrayWithGivenSum(arr, n, given_sum) ? "Yes" : "No");

    // Longest Consecutive Subsequence
    printf("Longest Consecutive Subsequence: %d\n", longestConsecutiveSubsequence(arr, n));

    // Largest Fibonacci Subset
    printf("Largest Fibonacci Subset: %d\n", largestFibonacciSubset(arr, n));

    // Consecutive Subset Partitioning
    printf("Consecutive Subset Partitioning: %d\n", partitionConsecutiveSubset(arr, n));

    // Distincts in Every Window of Size k
    printf("Distincts in Every Window of Size %d:\n", k);
    distinctsInEveryWindowOfSizeK(arr, n, k);

    // Insert, Delete, Search, and GetRandom (for Randomized Set)
    printf("Randomized Set Operations (Insert/Delete/Search/GetRandom):\n");
    // Implement Insert/Delete/Search/GetRandom

    // Min Insertions for Palindrome Permutation
    char str[] = "aab";
    printf("Min Insertions for Palindrome Permutation of '%s': %d\n", str, minInsertionsForPalindromePermutation(str));

    // Maximum Possible Difference of Two Subsets of an Array
    printf("Maximum Possible Difference of Two Subsets: %d\n", maxPossibleDifference(arr, n));

    // Sorting Using Trivial Hash Function
    printf("Sorting Using Trivial Hash Function:\n");
    sortUsingTrivialHashFunction(arr, n);

    // Smallest Subarray with k Distinct Numbers
    printf("Smallest Subarray with %d Distinct Numbers: %d\n", k, smallestSubarrayWithKDistinctNumbers(arr, n, k));

    // All Pairs (a, b) in an Array Such That a % b = k
    printf("All Pairs (a, b) in Array such that a %% b = %d:\n", k);
    findPairsWithModuloK(arr, n, k);

    // Group Words with Same Set of Characters
    printf("Group Words with Same Set of Characters:\n");
    // Implement the function here

    // k-th Distinct Element in an Array
    printf("k-th Distinct Element in Array (k = 2): %d\n", kthDistinctElement(arr, n, 2));

    return 0;
}
