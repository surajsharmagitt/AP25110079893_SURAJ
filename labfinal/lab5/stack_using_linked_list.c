// Stack Using Linked List (Input Safe)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void clearBuffer()
{
    while (getchar() != '\n');
}
void push()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value: ");
    if (scanf("%d", &x) != 1)
    {
        printf("Invalid input\n");
        clearBuffer();
        free(newnode);
        return;
    }
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Deleted element is %d\n", temp->data);
    top = top->next;
    free(temp);
}
void peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is %d\n", top->data);
    }
}
void display()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    temp = top;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4. Display\n5.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            clearBuffer();
            continue;
        }
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
