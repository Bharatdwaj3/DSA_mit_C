#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the start
void insertStart(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list iteratively
struct Node *reverseListIterative(struct Node *head)
{
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to reverse the list recursively
struct Node *reverseListRecursive(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Function to find the middle of the linked list using the Tortoise-Hare method
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to detect if there is a loop in the linked list
int hasLoop(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1; // Loop detected
        }
    }
    return 0; // No loop
}

// Function to find the starting point of the loop
struct Node *findLoopStart(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL; // No loop
}

// Function to find the length of the loop
int lengthOfLoop(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int length = 1;
            struct Node *temp = slow->next;
            while (temp != slow)
            {
                temp = temp->next;
                length++;
            }
            return length;
        }
    }
    return 0; // No loop
}

// Function to check if the linked list is a palindrome
int isPalindrome(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL, *next = NULL;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // If the list has odd length, move slow to the next node
    if (fast != NULL)
    {
        slow = slow->next;
    }

    // Compare the reversed first half with the second half
    while (slow != NULL)
    {
        if (slow->data != prev->data)
        {
            return 0; // Not a palindrome
        }
        slow = slow->next;
        prev = prev->next;
    }
    return 1; // Palindrome
}

// Function to segregate odd and even nodes
void segregateOddEven(struct Node **head){
    struct Node *odd = NULL, *even = NULL, *oddTail = NULL, *evenTail = NULL, *temp = *head;

    // Split the list into odd and even
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = temp;
                evenTail = even;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = temp;
                oddTail = odd;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }

    // Combine odd and even lists
    if (odd != NULL)
    {
        *head = odd;
        oddTail->next = even;
    }
    else
    {
        *head = even;
    }

    if (evenTail != NULL)
    {
        evenTail->next = NULL;
    }
}

// Function to remove the Nth node from the back of the list
void removeNthFromEnd(struct Node **head, int n){
    struct Node *fast = *head, *slow = *head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        *head = (*head)->next;
        return;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
}

// Function to delete the middle node of the linked list
void deleteMiddle(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct Node *slow = *head, *fast = *head, *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    free(slow);
}

// Function to sort the linked list
void sortList(struct Node **head)
{
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to sort a linked list containing 0's, 1's, and 2's using links
void sort012(struct Node **head)
{
    struct Node *zeroHead = NULL, *oneHead = NULL, *twoHead = NULL;
    struct Node *zeroTail = NULL, *oneTail = NULL, *twoTail = NULL;
    struct Node *temp = *head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            if (zeroHead == NULL)
            {
                zeroHead = temp;
                zeroTail = zeroHead;
            }
            else
            {
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
            }
        }
        else if (temp->data == 1)
        {
            if (oneHead == NULL)
            {
                oneHead = temp;
                oneTail = oneHead;
            }
            else
            {
                oneTail->next = temp;
                oneTail = oneTail->next;
            }
        }
        else
        {
            if (twoHead == NULL)
            {
                twoHead = temp;
                twoTail = twoHead;
            }
            else
            {
                twoTail->next = temp;
                twoTail = twoTail->next;
            }
        }
        temp = temp->next;
    }

    if (zeroTail != NULL)
    {
        zeroTail->next = oneHead;
    }
    if (oneTail != NULL)
    {
        oneTail->next = twoHead;
    }
    if (twoTail != NULL)
    {
        twoTail->next = NULL;
    }

    if (zeroHead != NULL)
    {
        *head = zeroHead;
    }
    else if (oneHead != NULL)
    {
        *head = oneHead;
    }
    else
    {
        *head = twoHead;
    }
}

// Function to find the intersection point of two linked lists
struct Node *getIntersectionPoint(struct Node *head1, struct Node *head2)
{
    int len1 = 0, len2 = 0;
    struct Node *temp1 = head1, *temp2 = head2;

    // Find lengths of both lists
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Move the pointer of the longer list to make the remaining lengths equal
    temp1 = head1;
    temp2 = head2;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            temp1 = temp1->next;
        }
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            temp2 = temp2->next;
        }
    }

    // Traverse both lists until we find the intersection
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

// Function to add 1 to a number represented by a linked list
void addOne(struct Node *head)
{
    struct Node *temp = head, *prev = NULL;
    int carry = 1;

    while (temp != NULL)
    {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        prev = temp;
        temp = temp->next;
    }

    if (carry)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = carry;
        newNode->next = NULL;
        prev->next = newNode;
    }
}

// Function to add two numbers represented by linked lists
struct Node *addTwoNumbers(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL, *temp = NULL;
    int carry = 0, sum;

    while (head1 != NULL || head2 != NULL || carry)
    {
        sum = carry;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        carry = sum / 10;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = NULL;
        if (result == NULL)
        {
            result = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp = newNode;
    }

    return result;
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    insertStart(&head1, 9);
    insertStart(&head1, 9);
    insertStart(&head1, 9);
    insertStart(&head1, 9);
    insertStart(&head2, 1);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node *sumList = addTwoNumbers(head1, head2);
    printf("Sum of Lists: ");
    printList(sumList);

    return 0;
}
