#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ch;
    int pos, i, len;

    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter character to insert: ");
    scanf(" %c", &ch);
    printf("Enter position: ");
    scanf("%d", &pos);

    len = strlen(str);
    for (i = len; i >= pos; i--)
    {
        str[i + 1] = str[i];
    }
    str[pos] = ch;

    printf("Updated string: %s\n", str);
    return 0;
}
