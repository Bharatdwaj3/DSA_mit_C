```C
#include <cmath>

bool isArmstrong(int n) {
    int org = n, sum = 0;
    int digits = 0, temp = n;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == org;
}

```

```C
bool isMagic(int n) {
    while (n > 9) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}


```