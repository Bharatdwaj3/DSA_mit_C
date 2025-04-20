#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, count = 0;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '1' && str[i + 1] == '1')
            count++;
    }

    printf("Count of consecutive 1’s: %d\n", count);
    return 0;
}
