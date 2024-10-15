#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
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

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full.\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->data[s->top];
}

int areStacksIdentical(Stack *s1, Stack *s2)
{
    if (s1->top != s2->top)
    {
        return 0;
    }

    Stack temp1, temp2;
    initStack(&temp1);
    initStack(&temp2);

    int identical = 1;

    while (!isEmpty(s1) && !isEmpty(s2))
    {
        int val1 = pop(s1);
        int val2 = pop(s2);

        if (val1 != val2)
        {
            identical = 0;
        }

        push(&temp1, val1);
        push(&temp2, val2);
    }

    while (!isEmpty(&temp1))
    {
        push(s1, pop(&temp1));
    }

    while (!isEmpty(&temp2))
    {
        push(s2, pop(&temp2));
    }

    return identical;
}

int main()
{
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    int n, value;

    printf("Enter number of elements in stack 1: ");
    scanf("%d", &n);
    printf("Enter elements of stack 1:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&s1, value);
    }

    printf("Enter number of elements in stack 2: ");
    scanf("%d", &n);
    printf("Enter elements of stack 2:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&s2, value);
    }

    if (areStacksIdentical(&s1, &s2))
    {
        printf("The stacks are identical.\n");
    }
    else
    {
        printf("The stacks are not identical.\n");
    }

    return 0;
}
