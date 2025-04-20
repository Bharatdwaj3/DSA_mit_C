#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, count = 0;

    printf("Enter a binary string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (str[i] == '1')
        {
            for (j = i + 1; j < len; j++)
            {
                if (str[j] == '1')
                    count++;
            }
        }
    }

    printf("Count of binary substrings: %d\n", count);
    return 0;
}
