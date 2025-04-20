#include<stdio.h>
#include<stdlib.h>

struct PriorityNode
{
    int data, priority;
    struct PriorityNode *next;
};

struct PriorityNode *pTop = NULL;

// Push with priority
void pushPriority(int data, int priority)
{
    struct PriorityNode *newNode = (struct PriorityNode *)malloc(sizeof(struct PriorityNode));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (pTop == NULL || pTop->priority < priority)
    {
        newNode->next = pTop;
        pTop = newNode;
        return;
    }

    struct PriorityNode *temp = pTop;
    while (temp->next != NULL && temp->next->priority >= priority)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Pop highest priority
void popPriority()
{
    if (pTop == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }
    struct PriorityNode *temp = pTop;
    pTop = pTop->next;
    free(temp);
}

// Delete at specific position
void deleteAtPriority(int position)
{
    if (pTop == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }
    struct PriorityNode *temp = pTop;
    if (position == 0)
    {
        pTop = pTop->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    struct PriorityNode *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}
