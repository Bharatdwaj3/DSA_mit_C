#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ch;
    int positions[10], n, i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter character to insert: ");
    scanf(" %c", &ch);
    printf("Enter number of positions: ");
    scanf("%d", &n);

    printf("Enter positions: ");
    for (i = 0; i < n; i++)
        scanf("%d", &positions[i]);

    len = strlen(str);
    for (i = 0; i < n; i++)
    {
        for (j = len; j >= positions[i]; j--)
            str[j + 1] = str[j];
        str[positions[i]] = ch;
        len++;
    }

    printf("Updated string: %s\n", str);
    return 0;
}
