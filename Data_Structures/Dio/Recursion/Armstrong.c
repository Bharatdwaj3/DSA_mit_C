#include <stdio.h>
#include <math.h>

// Recursive function to calculate sum of power of digits
int armstrongCheck(int n, int power, int sum)
{
    if (n == 0)
        return sum;
    return armstrongCheck(n / 10, power, sum + pow(n % 10, power));
}

// Function to count digits
int countDigits(int n)
{
    return (n == 0) ? 0 : 1 + countDigits(n / 10);
}

int main()
{
    int n, power, result;
    printf("Enter the number: ");
    scanf("%d", &n);

    power = countDigits(n);
    result = armstrongCheck(n, power, 0); // Calculate sum of power of digits

    printf("Sum of Digits Raised to Power %d: %d\n", power, result);

    if (result == n)
        printf("%d is an Armstrong Number.\n", n);
    else
        printf("%d is NOT an Armstrong Number.\n", n);

    return 0;
}
