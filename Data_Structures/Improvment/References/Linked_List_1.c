#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Singly Linked List Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Doubly Linked List Node
typedef struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// ========== 1. Swap nodes in pairs ==========
Node *swapPairs(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

// ========== 2. Design Browser History ==========
typedef struct BrowserHistory
{
    DNode *current;
} BrowserHistory;

DNode *createPage(const char *url)
{
    DNode *newPage = (DNode *)malloc(sizeof(DNode));
    newPage->data = strdup(url); // For simplicity, casted to int here
    newPage->prev = newPage->next = NULL;
    return newPage;
}

BrowserHistory *initBrowserHistory(const char *homepage)
{
    BrowserHistory *bh = (BrowserHistory *)malloc(sizeof(BrowserHistory));
    DNode *page = createPage(homepage);
    bh->current = page;
    return bh;
}

void visit(BrowserHistory *bh, const char *url)
{
    DNode *page = createPage(url);
    bh->current->next = page;
    page->prev = bh->current;
    bh->current = page;
}

void back(BrowserHistory *bh)
{
    if (bh->current->prev)
        bh->current = bh->current->prev;
}

void forward(BrowserHistory *bh)
{
    if (bh->current->next)
        bh->current = bh->current->next;
}

// ========== 3. Partition List ==========
Node *partition(Node *head, int x)
{
    Node *beforeStart = NULL, *beforeEnd = NULL;
    Node *afterStart = NULL, *afterEnd = NULL;

    while (head)
    {
        Node *next = head->next;
        head->next = NULL;
        if (head->data < x)
        {
            if (!beforeStart)
                beforeStart = beforeEnd = head;
            else
            {
                beforeEnd->next = head;
                beforeEnd = head;
            }
        }
        else
        {
            if (!afterStart)
                afterStart = afterEnd = head;
            else
            {
                afterEnd->next = head;
                afterEnd = head;
            }
        }
        head = next;
    }

    if (!beforeStart)
        return afterStart;
    beforeEnd->next = afterStart;
    return beforeStart;
}

// ========== 4. Pairs with Sum in Doubly Linked List ==========
void pairsWithSum(DNode *head, int target)
{
    DNode *left = head, *right = head;
    while (right && right->next)
        right = right->next;

    while (left && right && left != right && right->next != left)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            printf("(%d, %d)\n", left->data, right->data);
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
}

// ========== 5. Rotate Singly Linked List ==========
Node *rotateRight(Node *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;
    int len = 1;
    Node *tail = head;
    while (tail->next)
    {
        len++;
        tail = tail->next;
    }
    k = k % len;
    if (k == 0)
        return head;
    tail->next = head;
    Node *newTail = head;
    for (int i = 0; i < len - k - 1; i++)
        newTail = newTail->next;
    Node *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

// ========== 6. Rotate Doubly Linked List by N Nodes ==========
DNode *rotateDoublyList(DNode *head, int N)
{
    if (!head || N == 0)
        return head;
    DNode *current = head;
    int count = 1;
    while (count < N && current)
    {
        current = current->next;
        count++;
    }
    if (!current)
        return head;
    DNode *NthNode = current;
    DNode *newHead = NthNode->next;
    if (!newHead)
        return head;

    newHead->prev = NULL;
    NthNode->next = NULL;

    DNode *temp = newHead;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
    head->prev = temp;

    return newHead;
}

// ========== 7. Delete Node with Only Pointer ==========
void deleteNode(Node *node)
{
    if (!node || !node->next)
        return;
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

// ========== Utility Functions ==========
Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// ========== Main Function ==========
int main()
{
    // Create a sample list for demonstration
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List: ");
    printList(head);

    head = swapPairs(head);
    printf("After Swapping Pairs: ");
    printList(head);

    head = rotateRight(head, 2);
    printf("After Rotating Right by 2: ");
    printList(head);

    head = partition(head, 3);
    printf("After Partitioning at 3: ");
    printList(head);

    printf("Deleting node with only pointer (2nd node)...\n");
    deleteNode(head->next);
    printList(head);

    return 0;
}
