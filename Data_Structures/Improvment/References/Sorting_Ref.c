#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, temp, minIdx;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = 0; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        temp = arr[j];
        arr[j] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = A[low];
        int i = low + 1;
        int j = high;
        int temp;

        do
        {
            while (i <= high && A[i] <= pivot)
                i++;

            while (A[j] > pivot)
                j--;

            if (i < j)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        } while (i < j);

        temp = A[low];
        A[low] = A[j];
        A[j] = temp;

        quickSort(A, low, j - 1);
        quickSort(A, j + 1, high);
    }
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        int i = low, j = mid + 1, k = 0;
        int *temp = (int *)malloc((high - low + 1) * sizeof(int));

        while (i <= mid && j <= high)
        {
            if (A[i] < A[j])
                temp[k++] = A[i++];
            else
                temp[k++] = A[j++];
        }

        while (i <= mid)
            temp[k++] = A[i++];

        while (j <= high)
            temp[k++] = A[j++];

        for (i = low, k = 0; i <= high; i++, k++)
            A[i] = temp[k];

        free(temp);
    }
}
