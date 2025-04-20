#include <stdio.h>
#include <stdbool.h>

// Assuming this is your Node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Assuming head is declared globally

// Helper function to check if a number is prime
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Modified displayList function to show only prime nodes
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Prime Nodes in Linked List: ");
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

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    int index = 0;

    printf("Alternate Nodes in Linked List: ");
    while (temp != NULL)
    {
        if (index % 2 == 0) // print only even-indexed nodes (0-based)
        {
            printf("%d -> ", temp->data);
        }
        temp = temp->next;
        index++;
    }
    printf("NULL\n");
}
