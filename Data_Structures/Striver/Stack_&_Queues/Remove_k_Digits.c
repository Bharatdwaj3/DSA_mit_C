#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeKdigits(char *num, int k)
{
    int len = strlen(num);
    char *stack = (char *)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        while (top >= 0 && k > 0 && stack[top] > num[i])
        {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    for (int i = 0; i < len - k; i++)
    {
        printf("%c", stack[i]);
    }

    free(stack);
    return 0;
}

int main()
{
    char num[] = "1432219";
    int k = 3;
    removeKdigits(num, k);
    return 0;
}
