#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp[100];
    int n, i, len;

    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter number of rotations: ");
    scanf("%d", &n);

    len = strlen(str);
    n = n % len; 

    for (i = 0; i < len; i++) {
        temp[i] = str[(i + n) % len];
    }

    temp[len] = '\0';
    printf("Left Rotated String: %s\n", temp);

    return 0;
}
