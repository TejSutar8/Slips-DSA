#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->items[s->top];
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX] = "(a*(b+c)*((d-a)/b))";
    char postfix[MAX];

    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
