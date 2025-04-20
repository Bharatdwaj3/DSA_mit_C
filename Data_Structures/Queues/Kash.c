#include <stdio.h>
#define MAX 5

void push(int stack[], int *top, int x) {
    if (*top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    (*top)++;
    stack[*top] = x;
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped element: %d\n", stack[*top]);
    (*top)--;
}

void disp(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

int main() {
    int stack[MAX], top = -1, choice, x;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(stack, &top, x);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                disp(stack, top);
                break;
            case 4:
                peek(stack, top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}