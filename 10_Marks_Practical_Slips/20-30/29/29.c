#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int peek(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    init(&s);
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Peek\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            value = peek(&s);
            if (value != -1)
            {
                printf("Top value: %d\n", value);
            }
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
