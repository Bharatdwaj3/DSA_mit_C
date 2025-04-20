#include <stdio.h>

void printDigits(int n)
{
    if (n == 0)
        return;

    printDigits(n / 10);   
    printf("%d ", n % 10);
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        n = -n;      
        printf("- "); 
    }

    printf("Digits: ");
    if (n == 0)
    {
        printf("0"); 
    }else{
        printDigits(n);
    }

    printf("\n");

    return 0;
}
