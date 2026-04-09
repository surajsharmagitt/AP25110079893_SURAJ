// SINGLE LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(const char *msg, int *num)
{
    char input[100];
    printf("%s", msg);
    if (!fgets(input, sizeof(input), stdin))
        return 0;

    if (sscanf(input, "%d", num) != 1)
        return 0;
    return 1;
}
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
/* Create Node */
struct Node *createNode(int val)
{
    struct Node *n = malloc(sizeof(struct Node));
    if (!n)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}
/* Insert */
void insert(int val, int pos)
{
    struct Node *n = createNode(val);

    if (pos <= 1 || !head)
    {
        n->next = head;
        head = n;
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp->next && i < pos - 1; i++)
        temp = temp->next;
    n->next = temp->next;
    temp->next = n;
}
/* Delete */
void deleteNode(int pos)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (pos <= 1)
    {
        head = head->next;
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    for (int i = 1; temp && i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
/* Display */
void display()
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Length Helper */
int length()
{
    int count = 0;
    struct Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n--- Single Linked List Menu ---\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at Position\n");
        printf("4.Delete at Beginning\n");
        printf("5.Delete at End\n");
        printf("6.Delete at Position\n");
        printf("7.Display\n");
        printf("8.Exit\n");

        if (!getInt("Enter choice: ", &choice))
        {
            printf("Invalid input! Enter integer only.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            if (getInt("Enter value: ", &val))
                insert(val, 1);
            else
                printf("Invalid input.\n");
            break;
        case 2:
            if (getInt("Enter value: ", &val))
                insert(val, length() + 1);
            else
                printf("Invalid input.\n");
            break;
        case 3:
            if (getInt("Enter value: ", &val) &&
                getInt("Enter position: ", &pos))
                insert(val, pos);
            else
                printf("Invalid input.\n");
            break;
        case 4:
            deleteNode(1);
            break;
        case 5:
            deleteNode(length());
            break;
        case 6:
            if (getInt("Enter position: ", &pos))
                deleteNode(pos);
            else
                printf("Invalid input.\n");
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}
