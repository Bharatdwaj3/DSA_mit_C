#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, alpha[26] = {0}, count = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (alpha[str[i] - 'a'] == 0)
            {
                alpha[str[i] - 'a'] = 1;
                count++;
            }
        }
    }

    if (count == 26)
        printf("Pangram\n");
    else
        printf("Not a Pangram\n");

    return 0;
}
