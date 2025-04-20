#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[50], *token;
    int num, count = 0;

    printf("Enter an IP address: ");
    scanf("%s", ip);

    token = strtok(ip, ".");
    while (token != NULL)
    {
        num = atoi(token);
        if (num < 0 || num > 255)
        {
            printf("Invalid IP Address\n");
            return 0;
        }
        count++;
        token = strtok(NULL, ".");
    }

    if (count == 4)
        printf("Valid IP Address\n");
    else
        printf("Invalid IP Address\n");

    return 0;
}
