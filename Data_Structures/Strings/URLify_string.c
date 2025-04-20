#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], result[300];
    int i, j = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            result[j++] = '%';
            result[j++] = '2';
            result[j++] = '0';
        }
        else
        {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';
    printf("URLified String: %s\n", result);
    return 0;
}
