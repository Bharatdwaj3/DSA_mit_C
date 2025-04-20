#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *matrixToLinkedList(int rows, int cols, int matrix[rows][cols])
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Node *newNode = createNode(matrix[i][j]);

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return head;
}

void displayLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; 
    Node *head = matrixToLinkedList(2, 3, matrix);

    printf("Singly Linked List:\n");
    displayLinkedList(head);

    return 0;
}
