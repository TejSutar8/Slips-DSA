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

int main()
{
    struct Stack s;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Top element is %d\n", peek(&s));

    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));

    return 0;
}
