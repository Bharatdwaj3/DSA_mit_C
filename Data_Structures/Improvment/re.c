#include<stdio.h>
#include<stdlib.h>

void quickSort(int A[], int low, int high){
    if(low<high){
        int pivot=A[low];
        int i=low+1;
        int j=high;
        int temp;

        do{
            while(i<=high&&A[i]<=pivot)
                i++;
            while(A[j]>pivot)
                j--;
            if(i<j){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
        while(i<j);
            temp=A[low];
            A[low]=A[j];
            A[j]=temp;

            quickSort(A, low, j-1);
            quickSort(A, j+1, high);
        }
    }

void quickSort(int A[], int low, int high){
    if(low<high){
        int pivot=A[low];
        int i=low+1;
        int j=high;
        int temp;

        do{
            while(i<=high && A[i] <= pivot)
                i++;
            while(A[j]>pivot)
                j++;
        
            if(i<j){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }while(i<j);
        temp=A[low];
        A[j]=temp;

        quickSort(A, low, j-1);
        quickSort(A, j+1, high);
    }
}