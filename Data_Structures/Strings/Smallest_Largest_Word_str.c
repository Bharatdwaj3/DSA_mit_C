#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], *word, smallest[100], largest[100];

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    word = strtok(str, " ");
    strcpy(smallest, word);
    strcpy(largest, word);

    while (word)
    {
        if (strlen(word) < strlen(smallest))
            strcpy(smallest, word);
        if (strlen(word) > strlen(largest))
            strcpy(largest, word);

        word = strtok(NULL, " ");
    }

    printf("Smallest: %s\nLargest: %s\n", smallest, largest);
    return 0;
}
