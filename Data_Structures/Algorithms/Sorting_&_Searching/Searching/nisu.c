#include<stdio.h>

int partaion(int A[], int high, int low){
    int pivot=A[low];
    int i=low-1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j>pivot]){
            j--;
        }
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i < j);
        temp = A[low];
        A[low] = A[j];
        A[j] = temp;
        return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pIdx=partaion(arr,low,high);
        quickSort(arr,low,pIdx-1);
        quickSort(arr,pIdx+1,high);
    }
}