#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        if(isalnum(infix[i]))
            postfix[j++] = infix[i];

        else if(infix[i] == '(')
            push(infix[i]);

        else if(infix[i] == ')')
        {
            while(top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop();
        }

        else
        {
            while(top != -1 && precedence(peek()) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
