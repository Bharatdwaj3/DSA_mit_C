#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

int stack[MAX];
int top = -1; // Initially the stack is empty

int main() {
    int choice, value;

    // Push elements into the stack
    printf("Enter value to push onto stack: ");
    scanf("%d", &value);
    if (top == MAX - 1) {
        printf("Stack is full! Cannot push more elements.\n");
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }

    printf("Enter value to push onto stack: ");
    scanf("%d", &value);
    if (top == MAX - 1) {
        printf("Stack is full! Cannot push more elements.\n");
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }

    // Display the stack contents
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    // Pop an element from the stack
    if (top == -1) {
        printf("Stack is empty! Nothing to pop.\n");
    } else {
        value = stack[top--];
        printf("%d popped from stack.\n", value);
    }

    // Display the stack contents after pop
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
