void dpy_Fwd()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = head;
    printf("Doubly Linked List (Fwd): ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void dpy_Bwd()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = head;

    // Go to the last node (not NULL!)
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Doubly Linked List (Bwd): ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
