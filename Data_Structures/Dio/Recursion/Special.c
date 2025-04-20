#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n)
{
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

// Function to check if a number is special
int isSpecial(int n, int sum)
{
    if (n == 0)
        return sum;
    return isSpecial(n / 10, sum + factorial(n % 10));
}

int main()
{
    int n, result;
    printf("Enter the number: ");
    scanf("%d", &n);

    result = isSpecial(n, 0); // Calculate sum of factorial of digits

    printf("Sum of Factorials: %d\n", result);

    if (result == n)
        printf("%d is a Special Number.\n", n);
    else
        printf("%d is NOT a Special Number.\n", n);

    return 0;
}
