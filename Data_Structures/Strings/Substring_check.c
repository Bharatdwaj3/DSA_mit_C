#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], substr[50];

    printf("Enter the main string: ");
    scanf("%s", str);
    printf("Enter the substring: ");
    scanf("%s", substr);

    if (strstr(str, substr))
        printf("Substring Found\n");
    else
        printf("Substring Not Found\n");

    return 0;
}
