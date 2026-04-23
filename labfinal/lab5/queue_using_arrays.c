#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void clearBuffer()
{
    while(getchar() != '\n');
}

void enqueue()
{
    int x;

    if(rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value: ");
    if(scanf("%d", &x) != 1)
    {
        printf("Invalid input\n");
        clearBuffer();
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = x;
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);
    front++;
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

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
