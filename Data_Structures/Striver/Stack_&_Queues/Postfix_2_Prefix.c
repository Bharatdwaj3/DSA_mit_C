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

void postfixToPrefix(char *postfix)
{
    int n = strlen(postfix);

    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];
        if (isalnum(c))
        { // If operand
            char temp[2] = {c, '\0'};
            push(temp);
        }
        else
        { // If operator
            char op1[MAX], op2[MAX], result[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());

            sprintf(result, "%c%s%s", c, op1, op2);
            push(result);
        }
    }

    printf("Prefix Expression: %s\n", stack[top]);
}

int main()
{
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    postfixToPrefix(postfix);
    return 0;
}
