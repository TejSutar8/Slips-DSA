#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack
{
    int items[MAX];
    int top;
};

// Initialize the stack
void initialize(struct Stack *s)
{
    s->top = -1;
}

// Check if the stack is full
int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Push element onto stack
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop element from stack
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Display the stack
void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

void copyStack(struct Stack *src, struct Stack *dest)
{
    struct Stack temp;
    initialize(&temp);

    // Pop from src and push into temp
    while (!isEmpty(src))
    {
        push(&temp, pop(src));
    }

    // Pop from temp and push into both src and dest to maintain original order
    while (!isEmpty(&temp))
    {
        int value = pop(&temp);
        push(src, value);
        push(dest, value);
    }
}