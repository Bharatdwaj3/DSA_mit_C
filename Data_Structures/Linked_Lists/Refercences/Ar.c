#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

bool isPrime(int num)
{
    if (num <= 1)
        return false;

    int i = 2;
    while (i * i <= num)
    {
        if (num % i == 0)
            return false;
        i++;
    }
    return true;
}

// Palindrome number check using while loop
bool isPdrome(int num)
{
    int org = num;
    int rev = 0;
    while (num > 0)
    {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return org == rev;
}

// Magic number check using while loop
bool isMagik(int num)
{
    int sum;

    while (num > 9)
    {
        sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }

    return num == 1;
}

// Armstrong number check using while loop
bool isArmstrong(int num)
{
    int org = num;
    int sum = 0;
    int n = 0;
    int temp = num;

    while (temp > 0)
    {
        n++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0)
    {
        int digit = temp % 10;
        int power = 1;
        int j = 0;
        while (j < n)
        {
            power *= digit;
            j++;
        }

        sum += power;
        temp /= 10;
    }

    return sum == org;
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    printf("Prime Nodes in the Linked List: \n");
    while (temp != NULL)
    {
        if (isPrime(temp->data))
        {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayList_a()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    int index = 0;
    printf("Alternate Nodes in the Linked List: \n");
    while (temp != NULL)
    {
        if (index % 2 == 0)
        {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
        index++;
    }
    printf("NULL\n");
}

void displayList_b()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    printf("Prime Nodes in the Linked List: \n");
    while (temp != NULL)
    {
        if (isMagik(temp->data))
        {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayList_b()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    printf("Pallindrome Nodes in the Linked List: \n");
    while (temp != NULL)
    {
        if (isPdrome(temp->data))
        {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayList_c()
{
    if (head == NULL)
    {
        printf("List is empty!!");
        return;
    }
    struct Node *temp = head;
    printf("Pallindrome Nodes in the Linked List: \n");
    while (temp != NULL)
    {
        if (isArmstrong(temp->data))
        {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}