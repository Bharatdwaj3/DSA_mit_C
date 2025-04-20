#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack {
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// Function to push an element onto the stack
void push(struct stack *ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->arr[++ptr->top] = val;
    }
}

// Function to pop an element from the stack
int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1; // Error value
    } else {
        return ptr->arr[ptr->top--];
    }
}

// Function to reverse an array using a stack
void reverseArray(int arr[], int n) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = n;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // Push all elements onto the stack
    for (int i = 0; i < n; i++) {
        push(sp, arr[i]);
    }

    // Pop elements back into the array in reverse order
    for (int i = 0; i < n; i++) {
        arr[i] = pop(sp);
    }

    // Free allocated memory
    free(sp->arr);
    free(sp);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed array: ");
    printArray(arr, n);

    return 0;
}
