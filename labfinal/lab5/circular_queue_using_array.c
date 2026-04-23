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

    if((rear + 1) % SIZE == front)
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

    rear = (rear + 1) % SIZE;
    queue[rear] = x;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    i = front;
    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % SIZE;
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
