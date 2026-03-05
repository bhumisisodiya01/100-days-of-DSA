/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>

int precedence(char op)
{
    if(op=='+' || op=='-')
        return 1;
    if(op=='*' || op=='/')
        return 2;
    if(op=='^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], stack[100], postfix[100];
    int i, j=0, top=-1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i=0; infix[i]!='\0'; i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch=='(')
        {
            stack[++top] = ch;
        }
        else if(ch==')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else
        {
            while(top!=-1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while(top!=-1)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}