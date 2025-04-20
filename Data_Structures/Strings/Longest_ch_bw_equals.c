#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, maxLen = -1, first[256];

    printf("Enter a string: ");
    scanf("%s", str);

    memset(first, -1, sizeof(first));

    for (i = 0; str[i] != '\0'; i++)
    {
        if (first[str[i]] == -1)
            first[str[i]] = i;
        else
            maxLen = (i - first[str[i]] - 1 > maxLen) ? (i - first[str[i]] - 1) : maxLen;
    }

    printf("Longest substring between equal characters: %d\n", maxLen);
    return 0;
}
