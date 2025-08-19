// All-In-One C Implementation of Advanced Linked List Problems
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Basic Node Structures
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Utility Functions
Node *new_node(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

DNode *new_dnode(int data)
{
    DNode *temp = (DNode *)malloc(sizeof(DNode));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void print_list(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 1. Convert Singly Linked List to Circular
void convert_to_circular(Node *head)
{
    if (!head)
        return;
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
}

// 2. Reverse in groups
Node *reverse_in_groups(Node *head, int k)
{
    if (!head)
        return NULL;
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        head->next = reverse_in_groups(next, k);
    return prev;
}

// 3. Merge Two Sorted Lists
Node *merge_sorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->data < b->data)
    {
        a->next = merge_sorted(a->next, b);
        return a;
    }
    else
    {
        b->next = merge_sorted(a, b->next);
        return b;
    }
}

// 4. Remove Loop
void remove_loop(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return;
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

// 5. Check Palindrome
bool is_palindrome_helper(Node **left, Node *right)
{
    if (!right)
        return true;
    bool res = is_palindrome_helper(left, right->next);
    if (!res)
        return false;
    bool match = ((*left)->data == right->data);
    *left = (*left)->next;
    return match;
}

bool is_palindrome(Node *head)
{
    return is_palindrome_helper(&head, head);
}

int main()
{
    Node *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    printf("Original List: ");
    print_list(head);

    convert_to_circular(head);
    printf("Converted to Circular. Head -> %d\n", head->data);

    // Additional demonstrations can go here

    return 0;
}
