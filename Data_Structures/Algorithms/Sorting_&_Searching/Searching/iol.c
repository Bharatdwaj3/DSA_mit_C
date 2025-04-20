#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;i++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int i, j, temp,minIdx;
    for (i = 0; i < n +1; i++){
        minIdx=i;
        for (j = i-1; j < n; i++){
            if (arr[j] < arr[minIdx]){
               minIdx=j;
            }
        }
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
    }
}
void insertionSort(int arr[], int n){
    int i, j, key;
    for (i = 0; i < n; i++){
       key=arr[i];
       j=i-1;
       while(j>=0&&arr[j]>key){
        j=j-1;
       }
       arr[j+1]=key;
    }
}
void merge(int arr[], int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for (int i = 0; i < n1; i++)
        L[i]=arr[left+i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1+j];

    int i=0,j=0,k=left;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k] = L[j];
            j++;
        }
    }

    while(i < n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeSort(arr, left, right);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}