#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insert_begin(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end(int x)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Delete from beginning
void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_end()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Insert at position
void insert_pos(int x, int pos)
{
    struct node *newnode, *temp;
    int i = 1;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    temp = head;

    while(i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if(temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete at position
void delete_pos(int pos)
{
    struct node *temp, *nextnode;
    int i = 1;

    temp = head;

    while(i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

// Search
void search(int key)
{
    struct node *temp = head;
    int pos = 1;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

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

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
