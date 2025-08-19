#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Helper function to create a new node
Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to append to linked list
void append(Node **head, int data)
{
    Node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

// Helper function to print linked list
void print_list(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 1. PRIME NUMBERS
Node *generate_primes(int limit)
{
    Node *head = NULL;
    for (int i = 2; i <= limit; i++)
    {
        bool is_prime = true;
        if (i < 2)
            is_prime = false;
        for (int j = 2; j * j <= i && is_prime; j++)
        {
            if (i % j == 0)
                is_prime = false;
        }
        if (is_prime)
        {
            append(&head, i);
        }
    }
    return head;
}

// 2. ARMSTRONG NUMBERS (Narcissistic numbers)
Node *generate_armstrong(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        int original = i, sum = 0, digits = 0;
        int temp = i;

        // Count digits
        while (temp)
        {
            digits++;
            temp /= 10;
        }

        temp = i;
        // Calculate sum of digits raised to power
        while (temp)
        {
            int digit = temp % 10;
            int power = 1;
            for (int p = 0; p < digits; p++)
            {
                power *= digit;
            }
            sum += power;
            temp /= 10;
        }

        if (sum == original)
        {
            append(&head, i);
        }
    }
    return head;
}

// 3. PERFECT NUMBERS
Node *generate_perfect(int limit)
{
    Node *head = NULL;
    for (int i = 2; i <= limit; i++)
    {
        int sum = 1; // 1 is always a divisor
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
                if (j != i / j)
                    sum += i / j; // Add the pair divisor
            }
        }
        if (sum == i)
        {
            append(&head, i);
        }
    }
    return head;
}

// 4. FIBONACCI NUMBERS
Node *generate_fibonacci(int limit)
{
    Node *head = NULL;
    int a = 0, b = 1;
    while (a <= limit)
    {
        append(&head, a);
        int temp = a + b;
        a = b;
        b = temp;
    }
    return head;
}

// 5. PALINDROMIC NUMBERS
Node *generate_palindromic(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        int original = i, reversed = 0, temp = i;

        // Reverse the number
        while (temp)
        {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        if (original == reversed)
        {
            append(&head, i);
        }
    }
    return head;
}

// 6. HAPPY NUMBERS
Node *generate_happy(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        int n = i;
        // Continue until we reach 1 (happy) or 4 (unhappy cycle)
        while (n != 1 && n != 4)
        {
            int sum = 0;
            while (n)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        if (n == 1)
        {
            append(&head, i);
        }
    }
    return head;
}

// 7. TWIN PRIMES (primes that differ by 2)
Node *generate_twin_primes(int limit)
{
    Node *head = NULL;
    for (int i = 2; i <= limit - 2; i++)
    {
        // Check if i is prime
        bool i_prime = true;
        if (i < 2)
            i_prime = false;
        for (int j = 2; j * j <= i && i_prime; j++)
        {
            if (i % j == 0)
                i_prime = false;
        }

        // Check if i+2 is prime
        bool i2_prime = true;
        int i2 = i + 2;
        if (i2 < 2)
            i2_prime = false;
        for (int j = 2; j * j <= i2 && i2_prime; j++)
        {
            if (i2 % j == 0)
                i2_prime = false;
        }

        if (i_prime && i2_prime)
        {
            append(&head, i);
            append(&head, i2);
        }
    }
    return head;
}

// 8. MERSENNE PRIMES (2^p - 1 where p is prime)
Node *generate_mersenne_primes(int limit)
{
    Node *head = NULL;
    for (int p = 2; p <= 20; p++)
    {
        // Check if p is prime
        bool p_prime = true;
        if (p < 2)
            p_prime = false;
        for (int j = 2; j * j <= p && p_prime; j++)
        {
            if (p % j == 0)
                p_prime = false;
        }

        if (p_prime)
        {
            int mersenne = (1 << p) - 1; // 2^p - 1
            if (mersenne <= limit && mersenne > 0)
            {
                // Check if mersenne is prime
                bool mersenne_prime = true;
                if (mersenne < 2)
                    mersenne_prime = false;
                for (int j = 2; j * j <= mersenne && mersenne_prime; j++)
                {
                    if (mersenne % j == 0)
                        mersenne_prime = false;
                }
                if (mersenne_prime)
                {
                    append(&head, mersenne);
                }
            }
        }
    }
    return head;
}

// 9. SMITH NUMBERS (sum of digits = sum of digits of prime factors)
Node *generate_smith(int limit)
{
    Node *head = NULL;
    for (int i = 4; i <= limit; i++)
    {
        // Check if i is prime (Smith numbers are composite)
        bool i_prime = true;
        if (i < 2)
            i_prime = false;
        for (int j = 2; j * j <= i && i_prime; j++)
        {
            if (i % j == 0)
                i_prime = false;
        }

        if (!i_prime)
        { // Only check composite numbers
            // Calculate sum of digits of i
            int digit_sum = 0;
            int temp = i;
            while (temp)
            {
                digit_sum += temp % 10;
                temp /= 10;
            }

            // Calculate sum of digits of prime factors
            int factor_digit_sum = 0;
            int n = i;
            for (int f = 2; f * f <= n; f++)
            {
                while (n % f == 0)
                {
                    // Add digits of factor f
                    int factor_temp = f;
                    while (factor_temp)
                    {
                        factor_digit_sum += factor_temp % 10;
                        factor_temp /= 10;
                    }
                    n /= f;
                }
            }
            if (n > 1)
            { // Remaining prime factor
                while (n)
                {
                    factor_digit_sum += n % 10;
                    n /= 10;
                }
            }

            if (digit_sum == factor_digit_sum)
            {
                append(&head, i);
            }
        }
    }
    return head;
}

// 10. CATALAN NUMBERS
Node *generate_catalan(int count)
{
    Node *head = NULL;
    for (int n = 0; n < count; n++)
    {
        // Calculate nth Catalan number using recursion formula
        unsigned long long result = 1;
        if (n > 0)
        {
            result = 0;
            for (int i = 0; i < n; i++)
            {
                // Get catalan(i) and catalan(n-1-i)
                unsigned long long cat_i = 1, cat_n_i = 1;

                // Calculate catalan(i)
                if (i > 0)
                {
                    cat_i = 0;
                    for (int j = 0; j < i; j++)
                    {
                        unsigned long long inner = 1;
                        // This is getting complex - use binomial coefficient formula instead
                    }
                }

                // Use binomial coefficient formula: C(n) = (2n)! / ((n+1)! * n!)
                // Simplified: C(n) = (2n choose n) / (n+1)
                unsigned long long numerator = 1, denominator = 1;
                for (int k = 0; k < n; k++)
                {
                    numerator *= (2 * n - k);
                    denominator *= (k + 1);
                }
                result = numerator / denominator / (n + 1);
                break; // Use direct formula instead of recursion
            }
        }

        // Direct formula for Catalan numbers: C(n) = (2n)! / ((n+1)! * n!)
        unsigned long long catalan_n = 1;
        for (int i = 1; i <= n; i++)
        {
            catalan_n = catalan_n * (n + i) / i;
        }
        catalan_n = catalan_n / (n + 1);

        if (catalan_n <= INT_MAX)
        {
            append(&head, (int)catalan_n);
        }
        else
        {
            break;
        }
    }
    return head;
}

// 11. HARSHAD NUMBERS (divisible by sum of digits)
Node *generate_harshad(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        int digit_sum = 0;
        int temp = i;

        // Calculate sum of digits
        while (temp)
        {
            digit_sum += temp % 10;
            temp /= 10;
        }

        if (digit_sum != 0 && i % digit_sum == 0)
        {
            append(&head, i);
        }
    }
    return head;
}

// 12. KAPREKAR NUMBERS
Node *generate_kaprekar(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        if (i == 1)
        {
            append(&head, 1);
            continue;
        }

        long long square = (long long)i * i;
        int digits = 0;
        long long temp = square;

        // Count digits in square
        while (temp)
        {
            digits++;
            temp /= 10;
        }

        // Try all possible splits
        bool is_kaprekar = false;
        long long power = 1;
        for (int split = 1; split < digits && !is_kaprekar; split++)
        {
            power *= 10;
            long long left = square / power;
            long long right = square % power;
            if (right > 0 && left + right == i)
            {
                is_kaprekar = true;
            }
        }

        if (is_kaprekar)
        {
            append(&head, i);
        }
    }
    return head;
}

// 13. AUTOMORPHIC NUMBERS (end of n^2 is n)
Node *generate_automorphic(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        long long square = (long long)i * i;
        int temp = i;
        bool is_automorphic = true;

        // Check if last digits of square match the number
        while (temp > 0)
        {
            if (square % 10 != temp % 10)
            {
                is_automorphic = false;
                break;
            }
            square /= 10;
            temp /= 10;
        }

        if (is_automorphic)
        {
            append(&head, i);
        }
    }
    return head;
}

// 14. TRIANGULAR NUMBERS (n*(n+1)/2)
Node *generate_triangular(int limit)
{
    Node *head = NULL;
    int n = 1;
    while (true)
    {
        int triangular = n * (n + 1) / 2;
        if (triangular > limit)
            break;
        append(&head, triangular);
        n++;
    }
    return head;
}

// 15. PENTAGONAL NUMBERS (n*(3n-1)/2)
Node *generate_pentagonal(int limit)
{
    Node *head = NULL;
    int n = 1;
    while (true)
    {
        int pentagonal = n * (3 * n - 1) / 2;
        if (pentagonal > limit)
            break;
        append(&head, pentagonal);
        n++;
    }
    return head;
}

// 16. HEXAGONAL NUMBERS (n*(2n-1))
Node *generate_hexagonal(int limit)
{
    Node *head = NULL;
    int n = 1;
    while (true)
    {
        int hexagonal = n * (2 * n - 1);
        if (hexagonal > limit)
            break;
        append(&head, hexagonal);
        n++;
    }
    return head;
}

// 17. SQUARE NUMBERS (n^2)
Node *generate_square(int limit)
{
    Node *head = NULL;
    int n = 1;
    while (true)
    {
        int square = n * n;
        if (square > limit)
            break;
        append(&head, square);
        n++;
    }
    return head;
}

// 18. CUBE NUMBERS (n^3)
Node *generate_cube(int limit)
{
    Node *head = NULL;
    int n = 1;
    while (true)
    {
        int cube = n * n * n;
        if (cube > limit)
            break;
        append(&head, cube);
        n++;
    }
    return head;
}

// 19. FACTORIAL NUMBERS (n!)
Node *generate_factorial(int limit)
{
    Node *head = NULL;
    int n = 1;
    long long factorial = 1;
    while (factorial <= limit)
    {
        append(&head, (int)factorial);
        n++;
        factorial *= n;
        if (factorial > limit || factorial > INT_MAX)
            break;
    }
    return head;
}

// 20. ABUNDANT NUMBERS (sum of proper divisors > number)
Node *generate_abundant(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum > i)
        {
            append(&head, i);
        }
    }
    return head;
}

// 21. DEFICIENT NUMBERS (sum of proper divisors < number)
Node *generate_deficient(int limit)
{
    Node *head = NULL;
    for (int i = 2; i <= limit; i++)
    {
        int sum = 1; // 1 is always a proper divisor
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum < i)
        {
            append(&head, i);
        }
    }
    return head;
}

// 22. EMIRP NUMBERS (primes that give different primes when reversed)
Node *generate_emirp(int limit)
{
    Node *head = NULL;
    for (int i = 11; i <= limit; i++)
    {
        // Check if i is prime
        bool i_prime = true;
        if (i < 2)
            i_prime = false;
        for (int j = 2; j * j <= i && i_prime; j++)
        {
            if (i % j == 0)
                i_prime = false;
        }

        if (i_prime)
        {
            // Reverse the number
            int reversed = 0, temp = i;
            while (temp)
            {
                reversed = reversed * 10 + temp % 10;
                temp /= 10;
            }

            // Check if reversed is different and prime
            if (reversed != i)
            {
                bool rev_prime = true;
                if (reversed < 2)
                    rev_prime = false;
                for (int j = 2; j * j <= reversed && rev_prime; j++)
                {
                    if (reversed % j == 0)
                        rev_prime = false;
                }
                if (rev_prime)
                {
                    append(&head, i);
                }
            }
        }
    }
    return head;
}

// 23. LUCAS NUMBERS (similar to Fibonacci: L(n) = L(n-1) + L(n-2), L(0)=2, L(1)=1)
Node *generate_lucas(int limit)
{
    Node *head = NULL;
    int a = 2, b = 1;
    if (a <= limit)
        append(&head, a);
    if (b <= limit)
        append(&head, b);

    while (true)
    {
        int next = a + b;
        if (next > limit)
            break;
        append(&head, next);
        a = b;
        b = next;
    }
    return head;
}

// 24. PELL NUMBERS (P(n) = 2*P(n-1) + P(n-2), P(0)=0, P(1)=1)
Node *generate_pell(int limit)
{
    Node *head = NULL;
    int a = 0, b = 1;
    if (a <= limit)
        append(&head, a);
    if (b <= limit)
        append(&head, b);

    while (true)
    {
        int next = 2 * b + a;
        if (next > limit)
            break;
        append(&head, next);
        a = b;
        b = next;
    }
    return head;
}

// 25. TRIBONACCI NUMBERS (T(n) = T(n-1) + T(n-2) + T(n-3))
Node *generate_tribonacci(int limit)
{
    Node *head = NULL;
    int a = 0, b = 0, c = 1;
    if (a <= limit)
        append(&head, a);
    if (b <= limit)
        append(&head, b);
    if (c <= limit)
        append(&head, c);

    while (true)
    {
        int next = a + b + c;
        if (next > limit)
            break;
        append(&head, next);
        a = b;
        b = c;
        c = next;
    }
    return head;
}

// 26. PRONIC NUMBERS (n*(n+1))
Node *generate_pronic(int limit)
{
    Node *head = NULL;
    int n = 0;
    while (true)
    {
        int pronic = n * (n + 1);
        if (pronic > limit)
            break;
        append(&head, pronic);
        n++;
    }
    return head;
}

// 27. KEITH NUMBERS (numbers that appear in their own Fibonacci-like sequence)
Node *generate_keith(int limit)
{
    Node *head = NULL;
    for (int i = 10; i <= limit; i++)
    {
        // Get digits
        int digits[10], digit_count = 0, temp = i;
        while (temp)
        {
            digits[digit_count++] = temp % 10;
            temp /= 10;
        }

        // Reverse digits array
        for (int j = 0; j < digit_count / 2; j++)
        {
            int swap = digits[j];
            digits[j] = digits[digit_count - 1 - j];
            digits[digit_count - 1 - j] = swap;
        }

        // Generate sequence
        int sequence[1000];
        for (int j = 0; j < digit_count; j++)
        {
            sequence[j] = digits[j];
        }

        int pos = digit_count;
        while (sequence[pos - 1] < i)
        {
            int sum = 0;
            for (int j = 0; j < digit_count; j++)
            {
                sum += sequence[pos - digit_count + j];
            }
            sequence[pos] = sum;
            pos++;
            if (pos > 999)
                break; // Prevent overflow
        }

        if (sequence[pos - 1] == i)
        {
            append(&head, i);
        }
    }
    return head;
}

// 28. PALINDROMIC PRIMES
Node *generate_palindromic_primes(int limit)
{
    Node *head = NULL;
    for (int i = 2; i <= limit; i++)
    {
        // Check if prime
        bool is_prime = true;
        if (i < 2)
            is_prime = false;
        for (int j = 2; j * j <= i && is_prime; j++)
        {
            if (i % j == 0)
                is_prime = false;
        }

        if (is_prime)
        {
            // Check if palindrome
            int original = i, reversed = 0, temp = i;
            while (temp)
            {
                reversed = reversed * 10 + temp % 10;
                temp /= 10;
            }
            if (original == reversed)
            {
                append(&head, i);
            }
        }
    }
    return head;
}

// 29. SEMIPERFECT NUMBERS (equal to sum of some proper divisors)
Node *generate_semiperfect(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        // Get all proper divisors
        int divisors[1000], div_count = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                divisors[div_count++] = j;
            }
        }

        // Check all subsets using bit manipulation
        bool found = false;
        for (int mask = 1; mask < (1 << div_count) && !found; mask++)
        {
            int sum = 0;
            for (int j = 0; j < div_count; j++)
            {
                if (mask & (1 << j))
                {
                    sum += divisors[j];
                }
            }
            if (sum == i)
            {
                found = true;
            }
        }

        if (found)
        {
            append(&head, i);
        }
    }
    return head;
}

// 30. SPHENIC NUMBERS (product of exactly three distinct primes)
Node *generate_sphenic(int limit)
{
    Node *head = NULL;
    for (int i = 6; i <= limit; i++)
    {
        int prime_factors[3], factor_count = 0;
        int n = i;

        // Find prime factors
        for (int p = 2; p * p <= n && factor_count < 3; p++)
        {
            if (n % p == 0)
            {
                int count = 0;
                while (n % p == 0)
                {
                    n /= p;
                    count++;
                }
                if (count == 1)
                {
                    prime_factors[factor_count++] = p;
                }
                else
                {
                    factor_count = 0; // More than one occurrence
                    break;
                }
            }
        }

        if (n > 1)
        { // Remaining prime factor
            if (factor_count < 3)
            {
                prime_factors[factor_count++] = n;
            }
        }

        if (factor_count == 3)
        {
            append(&head, i);
        }
    }
    return head;
}

// 31. VAMPIRE NUMBERS (number with even digits that can be factored into two fangs)
Node *generate_vampire(int limit)
{
    Node *head = NULL;
    for (int i = 1000; i <= limit && i <= 9999; i++)
    { // 4-digit vampires
        // Count digits
        int digit_count = 0, temp = i;
        while (temp)
        {
            digit_count++;
            temp /= 10;
        }

        if (digit_count % 2 != 0)
            continue;

        int half_digits = digit_count / 2;
        int lower = 1, upper = 1;
        for (int j = 0; j < half_digits; j++)
        {
            lower *= 10;
        }
        lower /= 10;
        upper = lower * 10;

        // Check all factor pairs
        for (int fang1 = lower; fang1 <= upper && fang1 * fang1 <= i; fang1++)
        {
            if (i % fang1 == 0)
            {
                int fang2 = i / fang1;

                // Check if fangs have correct digit count
                int f1_digits = 0, f2_digits = 0;
                temp = fang1;
                while (temp)
                {
                    f1_digits++;
                    temp /= 10;
                }
                temp = fang2;
                while (temp)
                {
                    f2_digits++;
                    temp /= 10;
                }

                if (f1_digits == half_digits && f2_digits == half_digits)
                {
                    // Check if digits match (simplified check)
                    int original_digits[10] = {0};
                    int fang_digits[10] = {0};

                    temp = i;
                    while (temp)
                    {
                        original_digits[temp % 10]++;
                        temp /= 10;
                    }

                    temp = fang1;
                    while (temp)
                    {
                        fang_digits[temp % 10]++;
                        temp /= 10;
                    }
                    temp = fang2;
                    while (temp)
                    {
                        fang_digits[temp % 10]++;
                        temp /= 10;
                    }

                    bool match = true;
                    for (int d = 0; d < 10; d++)
                    {
                        if (original_digits[d] != fang_digits[d])
                        {
                            match = false;
                            break;
                        }
                    }

                    if (match)
                    {
                        append(&head, i);
                        break;
                    }
                }
            }
        }
    }
    return head;
}

// 32. CARMICHAEL NUMBERS (composite numbers n such that a^n ≡ a (mod n) for all a)
Node *generate_carmichael(int limit)
{
    Node *head = NULL;
    for (int n = 561; n <= limit; n += 2)
    { // Start from first Carmichael number, only odd
        // Check if composite
        bool is_prime = true;
        if (n < 2)
            is_prime = false;
        for (int i = 2; i * i <= n && is_prime; i++)
        {
            if (n % i == 0)
                is_prime = false;
        }

        if (!is_prime)
        { // Only check composite numbers
            bool is_carmichael = true;

            // Check Fermat's little theorem for small values of a
            for (int a = 2; a <= 10 && is_carmichael; a++)
            {
                if (n % a != 0)
                { // gcd(a,n) = 1
                    // Calculate a^n mod n using modular exponentiation
                    long long result = 1;
                    long long base = a % n;
                    long long exp = n;

                    while (exp > 0)
                    {
                        if (exp % 2 == 1)
                        {
                            result = (result * base) % n;
                        }
                        base = (base * base) % n;
                        exp /= 2;
                    }

                    if (result != a % n)
                    {
                        is_carmichael = false;
                    }
                }
            }

            if (is_carmichael)
            {
                append(&head, n);
            }
        }
    }
    return head;
}

// 33. WEIRD NUMBERS (abundant but not semiperfect)
Node *generate_weird(int limit)
{
    Node *head = NULL;
    for (int i = 1; i <= limit; i++)
    {
        // Check if abundant
        int sum = 0;
        int divisors[1000], div_count = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
                divisors[div_count++] = j;
            }
        }

        if (sum > i)
        { // Abundant
            // Check if not semiperfect
            bool is_semiperfect = false;
            for (int mask = 1; mask < (1 << div_count) && !is_semiperfect; mask++)
            {
                int subset_sum = 0;
                for (int j = 0; j < div_count; j++)
                {
                    if (mask & (1 << j))
                    {
                        subset_sum += divisors[j];
                    }
                }
                if (subset_sum == i)
                {
                    is_semiperfect = true;
                }
            }

            if (!is_semiperfect)
            {
                append(&head, i);
            }
        }
    }
    return head;
}

// LINKED LIST SPECIFIC OPERATIONS

// Check if linked list contains only prime numbers
bool list_all_primes(Node *head)
{
    while (head)
    {
        bool is_prime = true;
        if (head->data < 2)
            is_prime = false;
        for (int i = 2; i * i <= head->data && is_prime; i++)
        {
            if (head->data % i == 0)
                is_prime = false;
        }
        if (!is_prime)
            return false;
        head = head->next;
    }
    return true;
}

// Filter linked list to keep only prime numbers
Node *filter_primes(Node *head)
{
    Node *result = NULL;
    while (head)
    {
        bool is_prime = true;
        if (head->data < 2)
            is_prime = false;
        for (int i = 2; i * i <= head->data && is_prime; i++)
        {
            if (head->data % i == 0)
                is_prime = false;
        }
        if (is_prime)
        {
            append(&result, head->data);
        }
        head = head->next;
    }
    return result;
}

// Find sum of all prime numbers in linked list
int sum_primes_in_list(Node *head)
{
    int sum = 0;
    while (head)
    {
        bool is_prime = true;
        if (head->data < 2)
            is_prime = false;
        for (int i = 2; i * i <= head->data && is_prime; i++)
        {
            if (head->data % i == 0)
                is_prime = false;
        }
        if (is_prime)
        {
            sum += head->data;
        }
        head = head->next;
    }
    return sum;
}

// Count Armstrong numbers in linked list
int count_armstrong_in_list(Node *head)
{
    int count = 0;
    while (head)
    {
        int original = head->data, sum = 0, digits = 0;
        int temp = head->data;

        // Count digits
        while (temp)
        {
            digits++;
            temp /= 10;
        }

        temp = head->data;
        // Calculate sum of digits raised to power
        while (temp)
        {
            int digit = temp % 10;
            int power = 1;
            for (int p = 0; p < digits; p++)
            {
                power *= digit;
            }
            sum += power;
            temp /= 10;
        }

        if (sum == original)
            count++;
        head = head->next;
    }
    return count;
}

// DEMONSTRATION FUNCTION
int main()
{
    printf("=== NUMBER THEORY WITH LINKED LISTS (33 TYPES) ===\n\n");

    printf("1. Prime numbers up to 50:\n");
    Node *primes = generate_primes(50);
    print_list(primes);

    printf("\n2. Armstrong numbers up to 1000:\n");
    Node *armstrong = generate_armstrong(1000);
    print_list(armstrong);

    printf("\n3. Perfect numbers up to 10000:\n");
    Node *perfect = generate_perfect(10000);
    print_list(perfect);

    printf("\n4. First Fibonacci numbers up to 100:\n");
    Node *fibonacci = generate_fibonacci(100);
    print_list(fibonacci);

    printf("\n5. Palindromic numbers up to 200:\n");
    Node *palindromic = generate_palindromic(200);
    print_list(palindromic);

    printf("\n6. Happy numbers up to 100:\n");
    Node *happy = generate_happy(100);
    print_list(happy);

    printf("\n7. Twin primes up to 50:\n");
    Node *twin_primes = generate_twin_primes(50);
    print_list(twin_primes);

    printf("\n8. Mersenne primes up to 1000:\n");
    Node *mersenne = generate_mersenne_primes(1000);
    print_list(mersenne);

    printf("\n9. Smith numbers up to 100:\n");
    Node *smith = generate_smith(100);
    print_list(smith);

    printf("\n10. First 8 Catalan numbers:\n");
    Node *catalan_nums = generate_catalan(8);
    print_list(catalan_nums);

    printf("\n11. Harshad numbers up to 50:\n");
    Node *harshad = generate_harshad(50);
    print_list(harshad);

    printf("\n12. Kaprekar numbers up to 1000:\n");
    Node *kaprekar = generate_kaprekar(1000);
    print_list(kaprekar);

    printf("\n13. Automorphic numbers up to 100:\n");
    Node *automorphic = generate_automorphic(100);
    print_list(automorphic);

    printf("\n14. Triangular numbers up to 100:\n");
    Node *triangular = generate_triangular(100);
    print_list(triangular);

    printf("\n15. Pentagonal numbers up to 100:\n");
    Node *pentagonal = generate_pentagonal(100);
    print_list(pentagonal);

    printf("\n16. Hexagonal numbers up to 100:\n");
    Node *hexagonal = generate_hexagonal(100);
    print_list(hexagonal);

    printf("\n17. Square numbers up to 100:\n");
    Node *squares = generate_square(100);
    print_list(squares);

    printf("\n18. Cube numbers up to 100:\n");
    Node *cubes = generate_cube(100);
    print_list(cubes);

    printf("\n19. Factorial numbers up to 1000:\n");
    Node *factorials = generate_factorial(1000);
    print_list(factorials);

    printf("\n20. Abundant numbers up to 50:\n");
    Node *abundant = generate_abundant(50);
    print_list(abundant);

    printf("\n21. Deficient numbers up to 30:\n");
    Node *deficient = generate_deficient(30);
    print_list(deficient);

    printf("\n22. Emirp numbers up to 200:\n");
    Node *emirp = generate_emirp(200);
    print_list(emirp);

    printf("\n23. Lucas numbers up to 100:\n");
    Node *lucas = generate_lucas(100);
    print_list(lucas);

    printf("\n24. Pell numbers up to 100:\n");
    Node *pell = generate_pell(100);
    print_list(pell);

    printf("\n25. Tribonacci numbers up to 100:\n");
    Node *tribonacci = generate_tribonacci(100);
    print_list(tribonacci);

    printf("\n26. Pronic numbers up to 100:\n");
    Node *pronic = generate_pronic(100);
    print_list(pronic);

    printf("\n27. Keith numbers up to 1000:\n");
    Node *keith = generate_keith(1000);
    print_list(keith);

    printf("\n28. Palindromic primes up to 200:\n");
    Node *pal_primes = generate_palindromic_primes(200);
    print_list(pal_primes);

    printf("\n29. Semiperfect numbers up to 50:\n");
    Node *semiperfect = generate_semiperfect(50);
    print_list(semiperfect);

    printf("\n30. Sphenic numbers up to 100:\n");
    Node *sphenic = generate_sphenic(100);
    print_list(sphenic);

    printf("\n31. Vampire numbers up to 9999:\n");
    Node *vampire = generate_vampire(9999);
    print_list(vampire);

    printf("\n32. Carmichael numbers up to 10000:\n");
    Node *carmichael = generate_carmichael(10000);
    print_list(carmichael);

    printf("\n33. Weird numbers up to 100:\n");
    Node *weird = generate_weird(100);
    print_list(weird);

    // Demonstrate list operations
    printf("\n=== LIST OPERATIONS ===\n");
    printf("Count of Armstrong numbers in first 1000: %d\n",
           count_armstrong_in_list(generate_armstrong(1000)));

    return 0;
}