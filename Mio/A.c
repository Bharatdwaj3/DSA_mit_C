#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

void push(int stack[], int *top, int c)
{
    if (*top == MAX - 1)
    {
        printf("\nStack is full!\n");
        return;
    }
    stack[++(*top)] = c;
    printf("\nPushed %d into the stack!!\n", stack[*top]);
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack is empty!!\n");
        return -1;
    }
    return stack[*top--];
}

int precedence(char c){
    if(c=='A') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}


void infixToPostfix(char *infix){
    char postfix[MAX];
    int stack[MAX], top = -1;
    int j=0;
    for(int i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isalnum(c)){
            postfix[j++]=c;
        }else if(c=='('){
            push(stack,&top,c);
        }else if(c==')'){
            while(top!=-1&&stack[top]!='('){
                postfix[j++] = pop(stack,&top);
            }
            pop(stack,&top);
        }
        else{
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop(stack,&top);
            }
            push(stack,&top,c);
        }
    }
    while(top!=-1){
        postfix[j++]=pop(stack,&top);
    }
    postfix[j]='\0';
    printf("Postfix Expression : %s\n",postfix);
}


int main()
{
    char infix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;

}
