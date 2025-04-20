#include <stdio.h>

int main()
{
    char str[100];
    int i, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Binary String\n");
    else
        printf("Not a Binary String\n");

    return 0;
}
