#include <stdio.h>

// Recursive function to sum the digits of a number
int sumDigits(int n)
{
    return (n == 0) ? 0 : (n % 10) + sumDigits(n / 10);
}

int main()
{
    int n, square, sum;
    printf("Enter the number: ");
    scanf("%d", &n);

    square = n * n;
    sum = sumDigits(square);

    printf("Sum of Digits of Square (%d²): %d\n", n, sum);

    if (sum == n)
        printf("%d is a Neon Number.\n", n);
    else
        printf("%d is NOT a Neon Number.\n", n);

    return 0;
}
