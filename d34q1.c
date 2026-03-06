/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[100];
    int i = 0;

    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            int num = 0;
            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int b = pop();
            int a = pop();
            int result;

            if(exp[i] == '+') result = a + b;
            else if(exp[i] == '-') result = a - b;
            else if(exp[i] == '*') result = a * b;
            else if(exp[i] == '/') result = a / b;

            push(result);
            i++;
        }
        else
        {
            i++;
        }
    }

    printf("%d", pop());

    return 0;
}