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

void copyStack(Stack *source, Stack *destination)
{
    Stack temp;
    initStack(&temp);

    while (!isEmpty(source))
    {
        push(&temp, pop(source));
    }

    while (!isEmpty(&temp))
    {
        int value = pop(&temp);
        push(source, value);
        push(destination, value);
    }
}

void displayStack(Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack source, destination;
    initStack(&source);
    initStack(&destination);

    int n, value;

    printf("Enter number of elements in source stack: ");
    scanf("%d", &n);
    printf("Enter elements of source stack:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&source, value);
    }

    copyStack(&source, &destination);

    printf("Source stack: ");
    displayStack(&source);

    printf("Destination stack: ");
    displayStack(&destination);

    return 0;
}
