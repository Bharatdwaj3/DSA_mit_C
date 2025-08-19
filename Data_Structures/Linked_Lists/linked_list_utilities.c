
#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Doubly Linked List Node
struct DNode {
    int data;
    struct DNode *prev, *next;
};

// 1. Remove Every K-th Node from Singly Linked List
struct Node* removeEveryKth(struct Node* head, int k) {
    if (k <= 0) return head;
    if (k == 1) {
        while (head) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }
    struct Node* curr = head;
    int count = 1;
    while (curr && curr->next) {
        if ((count + 1) % k == 0) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
        count++;
    }
    return head;
}

// 2. Middle of a Linked List
struct Node* findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 3. Count Occurrences in a Linked List
int countOccurrences(struct Node* head, int x) {
    int count = 0;
    while (head) {
        if (head->data == x) count++;
        head = head->next;
    }
    return count;
}

// 4. Circular Linked List Traversal
void traverseCircular(struct Node* head) {
    if (!head) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// 5. Check if Circular
int isCircular(struct Node* head) {
    if (!head) return 1;
    struct Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

// 6. Count Nodes in Circular List
int countCircularNodes(struct Node* head) {
    if (!head) return 0;
    int count = 1;
    struct Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 7. Deletion from a Circular Linked List at position pos
struct Node* deleteAtPosCircular(struct Node* head, int pos) {
    if (!head || pos < 1) return head;
    struct Node *curr = head, *prev = NULL;
    if (pos == 1) {
        while (curr->next != head) curr = curr->next;
        if (curr == head) {
            free(head);
            return NULL;
        }
        curr->next = head->next;
        free(head);
        return curr->next;
    }
    curr = head;
    for (int i = 0; i < pos - 1; i++) {
        prev = curr;
        curr = curr->next;
        if (curr == head) return head;
    }
    prev->next = curr->next;
    free(curr);
    return head;
}

// 8. Convert Singly to Circular
struct Node* toCircular(struct Node* head) {
    if (!head) return NULL;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = head;
    return head;
}

// 9. Exchange First and Last Node in Circular List
struct Node* exchangeFirstLast(struct Node* head) {
    if (!head || head->next == head) return head;
    struct Node *prev = NULL, *last = head;
    while (last->next != head) {
        prev = last;
        last = last->next;
    }
    if (prev) {
        prev->next = head;
        last->next = head->next;
        head->next = head;
        head = last;
    }
    return head;
}

// 10. Delete a Node in Doubly Linked List
void deleteDNode(struct DNode** head_ref, struct DNode* del) {
    if (!*head_ref || !del) return;
    if (*head_ref == del) *head_ref = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
}

// 11. Reverse a Singly Linked List
struct Node* reverseSLL(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 12. Reverse a Doubly Linked List
struct DNode* reverseDLL(struct DNode* head) {
    struct DNode* temp = NULL;
    struct DNode* current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) head = temp->prev;
    return head;
}
