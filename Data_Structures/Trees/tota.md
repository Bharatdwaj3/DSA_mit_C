```C
struct Node* rev_S(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = head->next; 
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct Node* nextPair = curr->next->next;
        struct Node* second = curr->next;

        // Swap
        second->next = curr;
        curr->next = nextPair;

        // Connect previous swapped pair to the current one
        if (prev != NULL)
            prev->next = second;

        // Move forward
        prev = curr;
        curr = nextPair;
    }

    return newHead;
}


```


```C


void printPairsWithSum(struct Node* head, int target) {
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        int sum = curr->data + curr->next->data;
        if (sum == target) {
            printf("Pair found: (%d, %d)\n", curr->data, curr->next->data);
        }
        curr = curr->next;
    }
}


```


```C
struct Node* swapPairs(struct Node* head, int target) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* dummy = malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node* prev = dummy;
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct Node* first = curr;
        struct Node* second = curr->next;
        struct Node* nextPair = second->next;

        // Check if their sum equals the target
        if ((first->data + second->data) == target) {
            // Swap
            second->next = first;
            first->next = nextPair;
            prev->next = second;

            // Update pointers
            prev = first;
            curr = nextPair;
        } else {
            // No swap, move forward
            prev = curr;
            curr = curr->next;
        }
    }

    struct Node* newHead = dummy->next;
    free(dummy);
    return newHead;
}

```


```C

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* rotateDoublyLinkedList(struct DNode* head, int N) {
    if (head == NULL || N == 0)
        return head;

    struct DNode* tail = head;
    int count = 1;

    // Traverse to the N-th node
    while (count < N && tail != NULL) {
        tail = tail->next;
        count++;
    }

    // If N >= length of the list
    if (tail == NULL || tail->next == NULL)
        return head;

    struct DNode* newHead = tail->next;
    newHead->prev = NULL;

    // Disconnect after Nth node
    tail->next = NULL;

    // Go to the original tail
    struct DNode* end = newHead;
    while (end->next != NULL) {
        end = end->next;
    }

    // Connect original head after original tail
    end->next = head;
    head->prev = end;

    return newHead;
}


struct Node* deleteGivenNode(struct Node* node) {
    if (node == NULL || node->next == NULL) {
        return node;
    }

    struct Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
    return node;
}

```