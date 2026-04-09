//DOUBLY LINKED LIST (SAFE + MENU DRIVEN)
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
    struct Node *prev, *next;
};
struct Node *head = NULL;
struct Node *createNode(int val)
{
    struct Node *n = malloc(sizeof(struct Node));
    if (!n)
    {
        printf("Memory error\n");
        exit(1);
    }
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}
int length()
{
    int c = 0;
    struct Node *t = head;
    while (t)
    {
        c++;
        t = t->next;
    }
    return c;
}
void insert(int val, int pos)
{
    struct Node *n = createNode(val);

    if (pos <= 1 || !head)
    {
        n->next = head;
        if (head)
            head->prev = n;
        head = n;
        return;
    }
    struct Node *t = head;
    for (int i = 1; t->next && i < pos - 1; i++)
        t = t->next;

    n->next = t->next;
    if (t->next)
        t->next->prev = n;
    n->prev = t;
    t->next = n;
}
void deleteNode(int pos)
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }

    struct Node *t = head;

    if (pos <= 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        free(t);
        return;
    }

    for (int i = 1; t && i < pos; i++)
        t = t->next;

    if (!t)
    {
        printf("Out of bounds\n");
        return;
    }

    if (t->next)
        t->next->prev = t->prev;
    t->prev->next = t->next;
    free(t);
}
void display()
{
    struct Node *t = head;
    if (!t)
    {
        printf("List empty\n");
        return;
    }
    while (t)
    {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}
int main()
{
    int ch, val, pos;
    while (1)
    {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Pos\n");
        printf("4.Delete Begin\n5.Delete End\n6.Delete Pos\n");
        printf("7.Display\n8.Exit\n");

        if (!getInt("Choice: ", &ch))
        {
            printf("Invalid input\n");
            continue;
        }

        switch (ch)
        {
        case 1:
            if (getInt("Value: ", &val))
                insert(val, 1);
            break;
        case 2:
            if (getInt("Value: ", &val))
                insert(val, length() + 1);
            break;
        case 3:
            if (getInt("Value: ", &val) && getInt("Position: ", &pos))
                insert(val, pos);
            break;
        case 4:
            deleteNode(1);
            break;
        case 5:
            deleteNode(length());
            break;
        case 6:
            if (getInt("Position: ", &pos))
                deleteNode(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
