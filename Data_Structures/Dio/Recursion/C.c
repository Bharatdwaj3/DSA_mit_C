#include <stdio.h>

// Recursive function to convert octal to decimal
int octalToDecimal(int octal, int base)
{
    if (octal == 0)
        return 0;

    return (octal % 10) * base + octalToDecimal(octal / 10, base * 8);
}

int main()
{
    int octal, decimal;

    printf("Enter an octal number: ");
    scanf("%d", &octal);

    if (octal < 0)
    {
        printf("Negative octal numbers are not valid.\n");
        return 0;
    }

    decimal = octalToDecimal(octal, 1); // Start with base 8^0 = 1

    printf("Decimal Equivalent: %d\n", decimal);

    return 0;
}
