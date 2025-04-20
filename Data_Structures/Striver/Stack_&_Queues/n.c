#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int precedence(char c){
    if (c=='^') return 3;
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-') return 1;
    return 0;
}

void reverseString(char *str){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}

void infixToPrefix(char *infix)
{
    char prefix[MAX];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
           prefix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
               prefix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
               prefix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1)
    {
       prefix[j++] = pop();
    }
   prefix[j] = '\0';
    reverseString(prefix);
    printf("Postfix expression : %s\ns",prefix);
}

int main()
{
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix);
    return 0;
}