//CIRCULAR SINGLY LINKED LIST
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
struct Node *createNode(int val)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}
int length()
{
    if (!head)
        return 0;
    int c = 1;
    struct Node *t = head->next;
    while (t != head)
    {
        c++;
        t = t->next;
    }
    return c;
}
void insert(int val, int pos)
{
    struct Node *n = createNode(val);
    if (!head)
    {
        head = n;
        n->next = head;
        return;
    }
    if (pos <= 1)
    {
        struct Node *t = head;
        while (t->next != head)
            t = t->next;
        n->next = head;
        t->next = n;
        head = n;
        return;
    }
    struct Node *t = head;
    for (int i = 1; t->next != head && i < pos - 1; i++)
        t = t->next;

    n->next = t->next;
    t->next = n;
}
void deleteNode(int pos)
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }
    if (pos <= 1)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }
        struct Node *t = head;
        while (t->next != head)
            t = t->next;
        struct Node *temp = head;
        head = head->next;
        t->next = head;
        free(temp);
        return;
    }
    struct Node *t = head, *prev = NULL;
    for (int i = 1; t->next != head && i < pos; i++)
    {
        prev = t;
        t = t->next;
    }
    prev->next = t->next;
    free(t);
}
void display()
{
    if (!head)
    {
        printf("List empty\n");
        return;
    }
    struct Node *t = head;
    do
    {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != head);
    printf("(back to head)\n");
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
            printf("Invalid\n");
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
