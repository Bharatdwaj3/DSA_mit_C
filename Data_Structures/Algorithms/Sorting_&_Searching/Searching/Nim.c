#include <stdio.h>

// Utility function to print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ========== INSERTION SORT ==========
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ========== BUBBLE SORT ==========
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
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

// ========== SELECTION SORT ==========
void selectionSort(int arr[], int n)
{
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// ========== MERGE SORT ==========
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ========== QUICK SORT ==========
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // Swap pivot with element at j
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // Sort left subarray
        quickSort(arr, partitionIndex + 1, high); // Sort right subarray
    }
}

// ========== MAIN FUNCTION ==========
int main()
{
    // Test array
    int original[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(original) / sizeof(original[0]);

    printf("Original Array: ");
    printArray(original, n);
    printf("\n");

    // Test Bubble Sort
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Bubble Sort: ");
    bubbleSort(arr1, n);
    printArray(arr1, n);

    // Test Insertion Sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Insertion Sort: ");
    insertionSort(arr2, n);
    printArray(arr2, n);

    // Test Selection Sort
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Selection Sort: ");
    selectionSort(arr3, n);
    printArray(arr3, n);

    // Test Merge Sort
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Merge Sort: ");
    mergeSort(arr4, 0, n - 1);
    printArray(arr4, n);

    // Test Quick Sort
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    printf("Quick Sort: ");
    quickSort(arr5, 0, n - 1);
    printArray(arr5, n);

    return 0;
}