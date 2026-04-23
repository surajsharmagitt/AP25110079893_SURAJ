#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void clearBuffer()
{
    while(getchar() != '\n');
}

void push()
{
    int x;

    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter value: ");
    if(scanf("%d", &x) != 1)
    {
        printf("Invalid input\n");
        clearBuffer();
        return;
    }

    top++;
    stack[top] = x;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted element is %d\n", stack[top]);
    top--;
}

void peek()
{
    if(top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            clearBuffer();
            continue;
        }

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
