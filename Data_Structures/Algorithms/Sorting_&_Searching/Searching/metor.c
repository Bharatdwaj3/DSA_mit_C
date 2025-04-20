#include<stdio.h>
#include<stdlib.h>



void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partation(int A[],int low,int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;

    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partation(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi - 1,high);
    }
}
int main()
{
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
