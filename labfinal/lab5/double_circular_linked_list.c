#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insert_begin(int x)
{
    struct node *newnode, *last;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    if(head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}

// Insert at end
void insert_end(int x)
{
    struct node *newnode, *last;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    if(head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;
}

// Delete from beginning
void delete_begin()
{
    struct node *last, *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    last = head->prev;
    temp = head;

    head = head->next;

    last->next = head;
    head->prev = last;

    free(temp);
}

// Delete from end
void delete_end()
{
    struct node *last;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    last = head->prev;

    last->prev->next = head;
    head->prev = last->prev;

    free(last);
}

// Insert at position
void insert_pos(int x, int pos)
{
    struct node *newnode, *temp;
    int i = 1;

    if(pos == 1)
    {
        insert_begin(x);
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    temp = head;

    while(i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }

    if(temp->next == head && i < pos - 1)
    {
        printf("Invalid Position\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}

// Delete at position
void delete_pos(int pos)
{
    struct node *temp;
    int i = 1;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(pos == 1)
    {
        delete_begin();
        return;
    }

    temp = head;

    while(i < pos && temp->next != head)
    {
        temp = temp->next;
        i++;
    }

    if(temp->next == head && i < pos)
    {
        printf("Invalid Position\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

// Search
void search(int key)
{
    struct node *temp = head;
    int pos = 1;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    do
    {
        if(temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while(temp != head);

    printf("Element not found\n");
}

// Display
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

// Main
int main()
{
    int choice, value, pos;

    do
    {
        printf("\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Delete End\n");
        printf("5.Insert Position\n6.Delete Position\n7.Search\n8.Display\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                scanf("%d %d", &value, &pos);
                insert_pos(value, pos);
                break;

            case 6:
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 7:
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 9);

    return 0;
}
