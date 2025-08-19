#include<stdio.h>

int partation(int A[], int low, int high){
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
    
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partationIndex;
    if(low<high){
        partationIndex=partation(A, low, high);
        quickSort(A, low, partationIndex-1);
        quickSort(A, partationIndex+1,high);
    }
}