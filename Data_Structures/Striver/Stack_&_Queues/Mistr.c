

```markdown## #1. isPalindrome

    This function checks if a given number is a palindrome.

```c bool
    isPalindrome(int n)
{
    int org = n, rev = 0;
    while (n != 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return org == rev;
}
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }

    struct Node *temp = head;
    printf("Palindrome Nodes: ");

    // Iterate through the list and print palindrome nodes
    while (temp != NULL)
    {
        if (isPalindrome(temp->data))
        {
            printf("%d ->", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}
```

    -- -

    ## #2. isMagic




```c bool
    isMagic(int n)
{
    while (n > 9)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}
displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }

    struct Node *temp = head;
    printf("Palindrome Nodes: ");

    // Iterate through the list and print palindrome nodes
    while (temp != NULL)
    {
        if (isMajik(temp->data))
        {
            printf("%d ->", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}
```

    -- -

    ## #3. isArmstrong

        This function checks if a number is an Armstrong number.An Armstrong number is a number that is equal to the sum of its digits each raised to the power of the number of digits.

```c bool
        isArmstrong(int n)
{
    int org = n, sum = 0;
    int digits = 0, temp = n;

    // Count the number of digits
    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }

    temp = n;

    // Calculate the sum of digits raised to the power of the number of digits
    while (temp != 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == org;
}
displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }

    struct Node *temp = head;
    printf("Palindrome Nodes: ");

    // Iterate through the list and print palindrome nodes
    while (temp != NULL)
    {
        if (isArmstrong(temp->data))
        {
            printf("%d ->", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}
```

    -- -

    ## #4. displayList



```c void
    displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return;
    }

    struct Node *temp = head;
    printf("Palindrome Nodes: ");

    // Iterate through the list and print palindrome nodes
    while (temp != NULL)
    {
        if (isPalindrome(temp->data))
        {
            printf("%d ->", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}
```
