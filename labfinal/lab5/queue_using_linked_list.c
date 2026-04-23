#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void clearBuffer()
{
    while(getchar() != '\n');
}

void enqueue()
{
    int x;
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory not available\n");
        return;
    }

    printf("Enter value: ");
    if(scanf("%d", &x) != 1)
    {
        printf("Invalid input\n");
        clearBuffer();
        free(newnode);
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element is %d\n", temp->data);
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            clearBuffer();
            continue;
        }

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
