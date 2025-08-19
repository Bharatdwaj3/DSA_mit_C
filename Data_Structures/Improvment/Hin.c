#include<stdio.h>
#include<stdlib.h>
void insertionSort(int arr[], int n){
    int i,j,key;
    key=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>key){
        j=j-1;
    }
    arr[j+1]=key;
}

