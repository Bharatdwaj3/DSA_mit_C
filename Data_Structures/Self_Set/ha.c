#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int i, stack[5];
int top = -1;

int main() {
    int choice, value, n;

    // Push operation
    printf("Enter the no of elements that you want to push: ");
    scanf("%d", &n);

    printf("Enter the values to push into the stack: ");
    for (i = 0; i < n; i++) {
        if (top == MAX - 1) {
            printf("Stack is full!!!\n");
            break;
        } else {
            scanf("%d", &value);
            stack[++top] = value;
        }
    }

    // Display stack values
    printf("\nThe values in the stack: \n");
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    // Pop operation
    printf("Enter the no of elements that you want to pop: ");
    scanf("%d", &n);

    printf("Popping values from the stack:\n");
    for (i = 0; i < n; i++) {
        if (top == -1) {
            printf("Stack is empty!!!\n");
            break;
        } else {
            printf("Popped value: %d\n", stack[top--]);
        }
    }

    // Display stack values after popping
    printf("\nThe values in the stack after popping: \n");
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
