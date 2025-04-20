#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;

    int n; // Number of elements to add
    printf("How many elements do you want to add to the linked list? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failure");
            return 1;
        }

        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; // First element becomes the head
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) { // Traverse to the end of the list
                temp = temp->next;
            }
            temp->next = newNode; // Link the new node at the end
        }
    }

    // Print the linked list
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
