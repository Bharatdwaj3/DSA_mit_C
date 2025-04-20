#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself if it's the only node
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head) // Find last node
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode; // Move head to new node
    }
    printf("Inserted %d at the beginning of the list.\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode; // Circular link
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head) // Find last node
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Make it circular
    }
    printf("Inserted %d at the end of the list.\n", value);
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted %d from the list.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *last = head;
    while (last->next != head) // Find last node
    {
        last = last->next;
    }
    head = head->next; // Move head
    last->next = head; // Maintain circular link
    printf("Deleted %d from the beginning of the list.\n", temp->data);
    free(temp);
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted %d from the list.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head; // Maintain circular link
    printf("Deleted %d from the end of the list.\n", temp->data);
    free(temp);
}

void peek()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
int getLength() {
    if (head == NULL) return 0;
    int count = 0;
    struct Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int isCircular() {
    if (head == NULL) return 0;
    struct Node *temp = head;
    while (temp->next != NULL && temp->next != head) {
        temp = temp->next;
    }
    return (temp->next == head);
}

struct Node* search(int value) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    do {
        if (temp->data == value) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

void splitCircularLinkedList(struct Node** head1, struct Node** head2) {
    if (head == NULL || head->next == head) return;
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
}

void mergeCircularLinkedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        head = head2;
        return;
    }
    if (head2 == NULL) return;
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
}

void sortCircularLinkedList() {
    if (head == NULL) return;
    struct Node *temp1 = head, *temp2;
    int swapped;
    do {
        swapped = 0;
        temp2 = head;
        while (temp2->next != head) {
            if (temp2->data > temp2->next->data) {
                int temp = temp2->data;
                temp2->data = temp2->next->data;
                temp2->next->data = temp;
                swapped = 1;
            }
            temp2 = temp2->next;
        }
    } while (swapped);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    displayList();
    printf("Length: %d\n", getLength());
    printf("Is Circular: %d\n", isCircular());
    if (search(20)) printf("Found 20\n");
    struct Node *head1 = NULL, *head2 = NULL;
    splitCircularLinkedList(&head1, &head2);
    printf("First half: ");
    displayList();
    printf("Second half: ");
    displayList();
    return 0;
}
