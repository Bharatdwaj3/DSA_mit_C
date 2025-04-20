#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int pos, i, len;

    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter position to remove: ");
    scanf("%d", &pos);

    len = strlen(str);
    for (i = pos; i < len; i++)
    {
        str[i] = str[i + 1];
    }

    printf("Updated string: %s\n", str);
    return 0;
}
