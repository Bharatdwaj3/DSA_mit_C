#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100], str2[100];
    int k, diff = 0, i, count[26] = {0};

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Enter value of K: ");
    scanf("%d", &k);

    if (strlen(str1) != strlen(str2))
    {
        printf("Not K-Anagrams\n");
        return 0;
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }

    for (i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            diff += count[i];
    }

    if (diff <= k)
        printf("K-Anagrams\n");
    else
        printf("Not K-Anagrams\n");

    return 0;
}
