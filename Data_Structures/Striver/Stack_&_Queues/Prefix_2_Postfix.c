#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str)
{
    strcpy(stack[++top], str);
}

char *pop()
{
    return stack[top--];
}

void prefixToPostfix(char *prefix)
{
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isalnum(c))
        { // If operand
            char temp[2] = {c, '\0'};
            push(temp);
        }
        else
        { // If operator
            char op1[MAX], op2[MAX], result[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());

            sprintf(result, "%s%s%c", op1, op2, c);
            push(result);
        }
    }

    printf("Postfix Expression: %s\n", stack[top]);
}

int main()
{
    char prefix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    prefixToPostfix(prefix);
    return 0;
}
