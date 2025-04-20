#include <stdio.h>

// Recursive function to check for Duck number
int hasZero(int n)
{
    if (n == 0)
        return 0;
    if (n % 10 == 0)
        return 1;
    return hasZero(n / 10);
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    if (n < 0)
        n = -n; // Convert to positive if negative

    if (hasZero(n))
        printf("%d is a Duck Number.\n", n);
    else
        printf("%d is NOT a Duck Number.\n", n);

    return 0;
}
