#include<stdio.h>
#include<stdlib.h>

void nextSmallerElement(int *arr, int n){
    int *stack = (int *)malloc(n*sizeof(int));
    int *result = (int *)malloc(n * sizeof(int));
    int top=-1;

    for(int i=0;i<n;i++){
        result[i]=-1;
    }

    for(int i=0;i<n;i++){
        while(top>=arr[stack[top]]>arr[i]){
            result[stack[top]]=arr[i];
            top--;
        }
        stack[++top]=i;
    }
    for(int i=0;i<n;i++){
        printf("%d",result[i]);
    }
    printf("\n");
    free(stack);
    free(result);
}

int main(){
    int arr[]={4,5,6,67,12};
    int ns=sizeof(arr)/sizeof(arr[0]);
    nextSmallerElement(arr,n);
    return 0;
}