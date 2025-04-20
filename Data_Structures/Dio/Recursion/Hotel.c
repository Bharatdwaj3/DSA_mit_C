

#include<stdio.h>

int num(int n)
{
    if (n == 0){
        return 1;
    }else{
        return n*num(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    printf("The Number list: ");
    if(n<0){
        printf("Factorial is not defined for -ve integers\n");
    }else{
        printf("\nFactorial of %d is %d\n",n,num(n));
    }
    
    return 0;
}