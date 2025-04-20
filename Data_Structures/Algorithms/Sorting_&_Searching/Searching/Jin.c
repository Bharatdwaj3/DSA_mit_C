#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)

{
    if (low < high)
    {
        int mid = (low + high) / 2;

       
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        int i = low, j = mid + 1, k = low;
        int B[100]; 
        while (i <= mid && j <= high)
        {
            if (A[i] < A[j])
            {
                B[k] = A[i];
                i++;
            }
            else
            {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
        while (j <= high)
        {
            B[k] = A[j];
            j++;
            k++;
        }
        for (i = low; i <= high; i++)
        {
            A[i] = B[i];
        }
    }
}


int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}
