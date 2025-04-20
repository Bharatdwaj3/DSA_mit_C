#include <stdio.h>

int num(int n) {
    if (n < 0) {
        return 1;
    }

    int result = num(n - 1); // First, complete recursion
    printf("%d ", n);  // Then, print in ascending order

    return n * result; // Continue multiplying for factorial
}

int main() {
    int n, result;

    printf("Enter the limit of the series: ");
    scanf("%d", &n);

    printf("The list of numbers: ");
    result = num(n);

    printf("\nFactorial of %d: %d\n", n, result);

    return 0;
}
