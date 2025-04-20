#include<stdio.h>

int find(int decimal_number){
    if(decimal_number==0)
        return 0;
    else   
        return (decimal_number%2+10*find(decimal_number/2));
}

int findSum(int A[],int N){
    if(N<=0)
        return 0;
    return (findSum(A, N-1)+(A[N-1]));
}

int main(){

    int A[]={1,2,3,4,5,5};
    int N=sizeof(A)/sizeof(A[0]);
    int decimal_number=10;

    printf("\n%d as decimal number : %d \n",decimal_number,find(decimal_number));
    printf("\nSum of the array elements : %d \n",findSum(A,N));
    
    return 0;

}