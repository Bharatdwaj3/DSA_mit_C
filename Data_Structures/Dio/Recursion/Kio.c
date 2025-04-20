#include <stdio.h>

// Function to reverse the number recursively
int reverseNumber(int n, int rev) {
    if (n == 0)
        return rev;
    return reverseNumber(n / 10, rev * 10 + (n % 10));
}

int main() {
    int n, original, reversed;
    printf("Enter the number: ");
    scanf("%d", &n);

    original = n; // Store original number

    if (n < 0) {
        printf("Negative numbers cannot be palindromes.\n");
        return 0;
    }

    reversed = reverseNumber(n, 0); // Reverse the number

    printf("Reversed Number: %d\n", reversed);

    if (original == reversed)
        printf("%d is a Palindrome.\n", original);
    else
        printf("%d is NOT a Palindrome.\n", original);

    return 0;
}
