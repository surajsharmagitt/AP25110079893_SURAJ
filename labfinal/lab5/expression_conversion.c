// Expression conversion including infix to prefix and infix to postfix.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}
void reverse(char *exp)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--)
    {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}
void infixToPostfix(char infix[], char postfix[])
{
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            if (top != -1)
                top--;
        }
        else
        {
            while (top != -1 && getPriority(stack[top]) >= getPriority(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}
void infixToPrefix(char infix[], char prefix[])
{
    char tempInfix[MAX];
    strcpy(tempInfix, infix);

    reverse(tempInfix);
    for (int i = 0; tempInfix[i] != '\0'; i++)
    {
        if (tempInfix[i] == '(')
        {
            tempInfix[i] = ')';
        }
        else if (tempInfix[i] == ')')
        {
            tempInfix[i] = '(';
        }
    }
    char postfix[MAX];
    infixToPostfix(tempInfix, postfix);

    reverse(postfix);
    strcpy(prefix, postfix);
}
int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    return 0;
}