#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int n){
    int i,j,temp,minIdx;
    for(i=0;i<n-1;i++){
        minIdx=i;
        for(j=0;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
            temp=arr[j];
            arr[j]=arr[minIdx];
            arr[minIdx]=temp;
        }
    }
}

void selectionSort(int arr[], int n){
    int i,j,temp,minIdx;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
            temp=arr[j];
            arr[j]=arr[minIdx];
            arr[minIdx]=temp;
        }
    }
}