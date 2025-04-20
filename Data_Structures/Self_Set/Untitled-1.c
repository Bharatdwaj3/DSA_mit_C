#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
    if(top==MAX-1){
        printf("Stack overflow\n");
        return ;
    }
    stack[++top]=c;
}
char pop(){
    if(top==-1){
        return '\0';
    }return stack[top--];
}

int precedence (char c){
    if(c=='A') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

void infixToPostfix(char *infix){
    char postfix[MAX];
    int j=0;
    for(int i=0;infix[i]!='\0';i++){
        char c=infix[i];
        if(isalnum(c)){
            postfix[j++]=c;
        }
        else if(c=='('){
            push(c);
        }else if (c==')'){
            while (top!=-1&&stack[top]!='(')
            {
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(top!=-1&&precedence(stack[top])>=precendence(c)){
                postfix[j++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix Expression: %s\n",postfix);
}
int main(){
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s",infix);
    infixToPostfix(infix);
    return 0;
}