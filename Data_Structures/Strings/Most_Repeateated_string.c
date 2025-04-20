#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], words[50][50];
    int i, j, count[50] = {0}, wordCount = 0, first = 0, second = -1;

    printf("Enter a sequence: ");
    scanf(" %[^\n]", str);

    char *token = strtok(str, " ");
    while (token)
    {
        strcpy(words[wordCount], token);
        for (i = 0; i < wordCount; i++)
        {
            if (strcmp(words[i], token) == 0)
            {
                count[i]++;
                break;
            }
        }
        if (i == wordCount)
            count[wordCount++] = 1;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < wordCount; i++)
    {
        if (count[i] > count[first])
        {
            second = first;
            first = i;
        }
        else if (count[i] > count[second] && i != first)
        {
            second = i;
        }
    }

    printf("Second Most Repeated Word: %s\n", words[second]);
    return 0;
}
