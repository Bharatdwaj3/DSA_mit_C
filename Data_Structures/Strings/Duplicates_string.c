#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int count[256] = {0}, i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        count[str[i]]++;
    }

    printf("Duplicate characters: ");
    for (i = 0; i < 256; i++)
    {
        if (count[i] > 1)
        {
            printf("%c ", i);
        }
    }

    return 0;
}
