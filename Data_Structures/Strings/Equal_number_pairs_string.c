#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, count = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
                count++;
        }
    }

    printf("Equal Pairs Count: %d\n", count);
    return 0;
}
