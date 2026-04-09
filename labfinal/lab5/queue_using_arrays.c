#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = val;
    printf("%d enqueued to queue\n", val);
}
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front++];
    if (front > rear)
    {
        front = rear = -1; // Reset it
    }
    return val;
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
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
