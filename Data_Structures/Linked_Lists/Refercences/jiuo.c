#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning of the list\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end of the list\n", value);
}

void displayList(struct Node *listHead) {
    if (listHead == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = listHead;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != listHead);
    printf("(head)\n");
}

void splitCircularLinkedList(struct Node **head1, struct Node **head2) {
    if (head == NULL || head->next == head) {
        printf("Cannot split. List too small!\n");
        return;
    }
    struct Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1 = head;
    *head2 = slow->next;
    slow->next = *head1;
    
    struct Node *temp = *head2;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = *head2;
    
    printf("List successfully split!\n");
    printf("First Half: ");
    displayList(*head1);
    printf("Second Half: ");
    displayList(*head2);
}

void mergeCircularLinkedLists(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) {
        head = head2;
        return;
    }
    if (head2 == NULL) {
        head = head1;
        return;
    }
    
    struct Node *temp = head1;
    while (temp->next != head1) {
        temp = temp->next;
    }
    temp->next = head2;
    
    temp = head2;
    while (temp->next != head2) {
        temp = temp->next;
    }
    temp->next = head1;

    head = head1;
    
    printf("Lists merged successfully!\n");
    displayList(head);
}

int main() {
    int choice, value;
    struct Node *head1 = NULL, *head2 = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Split List\n");
        printf("5. Merge Lists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                splitCircularLinkedList(&head1, &head2);
                break;
            case 5:
                mergeCircularLinkedLists(head1, head2);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}
