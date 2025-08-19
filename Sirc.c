#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define MAXN 100

int heap[MAXN];
int heapSize=0;
int isMinHeap=1;

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int cmp(int a, int b){
    return isMinHeap ? a < b: a>b;
}

void heapify(int i){
    int extreme=i;
    int left=2*i+1, right=2*i+2;
    if(left<heapSize &&  cmp(heap[left], heap[extreme]))
        extreme=left;
    if(right < heapSize && cmp(heap[right], heap[extreme]))
        extreme = right;
    if(extreme != i){
        swap(&heap[i], &heap[extreme]);
        heapify(extreme);
    }
    if(extreme!=i){
        swap(&heap[i], &heap[extreme]);
        heapify(extreme);
    }
}

int extractTop(){
    int top=heap[0];
    heap[0]=heap[--heapSize];
    heapify(0);
    return top;
}

void insertHeap(int val){
    heap[heapSize++]=val;
    int i=heapSize-1;
    while(i && cmp(heap[i], heap[(i-1)/2])){
        swap(&heap[i], &heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void buildHeap(int arr[], int n, int minHeap){
    isMinHeap=minHeap;
    for(int i=0;i<n;i++)
        heap[i]=arr[i];
    for(int i=n/2-1;i>=0;i--)
        heapify(i);
}

int connectSticks(int arr[], int n){
    buildHeap(arr, n, 1);
    int total=0;
    while(heapSize>1){
        int a=extractTop();
        int b=extractTop();
        total += a+b;
        insertHeap(a+b);
    }
    return total;
}

void kClosestPoints(int arr[], int n, int k){
    buildHeap(arr, n, 0);
    while(heapSize> k)
        extractTop();
    printf("Top %d closest points: ",k);
    for(int i=0;)
}