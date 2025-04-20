#include <stdio.h>

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}


int binarySearch(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key); 
        else
            return binarySearch(arr, mid + 1, right, key); 
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    
    int linearResult = linearSearch(arr, size, key);
    if (linearResult != -1)
        printf("Linear Search: Element found at index %d\n", linearResult);
    else
        printf("Linear Search: Element not found\n");

   
    int binaryResult = binarySearch(arr, 0, size - 1, key);
    if (binaryResult != -1)
        printf("Binary Search: Element found at index %d\n", binaryResult);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
