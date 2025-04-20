#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ch;
    int i, j;

    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter character to remove: ");
    scanf(" %c", &ch);

    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ch)
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("Updated string: %s\n", str);
    return 0;
}
