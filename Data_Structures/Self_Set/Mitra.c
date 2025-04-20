void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failure\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head; // Point newNode to the current head
    *head = newNode;       // Update the head to the new node
    printf("Node with value %d inserted at the beginning\n", value);
}
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failure\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
 
    if (*head == NULL)
    {
        *head = newNode; // If the list is empty, the new node becomes the head
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Append at the end
    }
    printf("Node with value %d inserted at the end\n", value);
}
void deleteAtStart(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head; // Store the current head
    *head = (*head)->next;     // Update head to the next node
    printf("Node with value %d deleted from the start\n", temp->data);
    free(temp); // Free the old head
}
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) // If there's only one node
    {
        printf("Node with value %d deleted from the end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Traverse to the second-to-last node
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL; // Disconnect the last node
    printf("Node with value %d deleted from the end\n", temp->data);
    free(temp); // Free the last node
}
