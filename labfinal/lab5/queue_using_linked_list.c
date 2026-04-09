#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    printf("%d enqueued to queue\n", val);
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node *temp = front;
    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    int val = temp->data;
    free(temp);
    return val;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val != -1)
                printf("Dequeued %d\n", val);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}