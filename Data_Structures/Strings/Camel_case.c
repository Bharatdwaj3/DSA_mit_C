#include <stdio.h>

int main()
{
    char str[100];
    int i, capitalize = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            capitalize = 1;
        }
        else
        {
            if (capitalize && str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
            printf("%c", str[i]);
            capitalize = 0;
        }
    }

    return 0;
}
