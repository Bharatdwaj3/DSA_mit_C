#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int arr[MAX];

int main()
{

    int n, i;

    printf("Enter the limit of the array : ");
    scanf("%d", &n);

    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The Elements of the array : ");
    for (i = 0; i < n; i++)
    {
        printf("\n %d",arr[i]);
    }
}