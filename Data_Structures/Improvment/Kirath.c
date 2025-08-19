#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n){
    int i,j,key;
    for(i=0;i<n;i++){
        key=arr[j];
        j=i-1;
        while(j>=0&&arr[j]>key){
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void insertSort(int arr[], int n){
    int i,j,key;
    for(i=0;i<n;i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}