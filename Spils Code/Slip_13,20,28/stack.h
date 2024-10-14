#include <stdio.h>
#define MAX 100

struct Stack
{
    int data[MAX];
    int top;
};

void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}
