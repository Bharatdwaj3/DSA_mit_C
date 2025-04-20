#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], subseq[50];
    int i, j = 0;

    printf("Enter the main string: ");
    scanf("%s", str);
    printf("Enter the subsequence: ");
    scanf("%s", subseq);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == subseq[j])
            j++;
    }

    if (subseq[j] == '\0')
        printf("Subsequence Found\n");
    else
        printf("Not a Subsequence\n");

    return 0;
}
