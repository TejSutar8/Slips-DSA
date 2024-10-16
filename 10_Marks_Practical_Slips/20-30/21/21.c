#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char items[MAX];
    int top;
} Stack;

void init(Stack *s)
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

void reverseString(char str[])
{
    Stack s;
    init(&s);
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        push(&s, str[i]);
    }

    for (int i = 0; i < n; i++)
    {
        str[i] = pop(&s);
    }
}

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
