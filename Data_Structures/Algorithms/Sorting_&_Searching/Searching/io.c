#include <stdio.h>

void insertSort(int arr[], int n){
    int i, key, j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j+1;
        }
        arr[j+1]=key;
    }
}

void bubbleSort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){

        for(j=0;j<n-i-1;j++){
        
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(int arr[],int n){
    int i,j,minIdx,temp;
    for(i=0;i<n-1;i++){
        minIdx=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
            temp=arr[i];
            arr[i]=arr[minIdx];
            arr[minIdx]=temp;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    // Choose which sorting algorithm to use
    printf("\nBubble Sort: ");
    bubbleSort(arr, n);
    printArray(arr, n);

    // Reset array for next sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    printf("\nInsertion Sort: ");
    insertionSort(arr2, n);
    printArray(arr2, n);

    // Reset array for next sort
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    printf("\nSelection Sort: ");
    selectionSort(arr3, n);
    printArray(arr3, n);

    return 0;
}
