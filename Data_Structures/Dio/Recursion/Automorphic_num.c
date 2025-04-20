#include <stdio.h>

// Recursive function to check if last digits match
int isAutomorphic(int n, int square)
{
    if (n == 0)
        return 1;
    if (n % 10 != square % 10)
        return 0;
    return isAutomorphic(n / 10, square / 10);
}

int main()
{
    int n, square;
    printf("Enter the number: ");
    scanf("%d", &n);

    square = n * n;

    printf("Square: %d\n", square);

    if (isAutomorphic(n, square))
        printf("%d is an Automorphic Number.\n", n);
    else
        printf("%d is NOT an Automorphic Number.\n", n);

    return 0;
}
