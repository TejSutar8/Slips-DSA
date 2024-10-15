#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack
{
    int top;
    float items[MAX];
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

void push(Stack *s, float value)
{
    if (!isFull(s))
    {
        s->items[++(s->top)] = value;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

float pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[(s->top)--];
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

float evaluatePostfix(char postfix[], float a, float b, float c, float d)
{
    Stack stack;
    init(&stack);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (ch == 'a')
        {
            push(&stack, a);
        }
        else if (ch == 'b')
        {
            push(&stack, b);
        }
        else if (ch == 'c')
        {
            push(&stack, c);
        }
        else if (ch == 'd')
        {
            push(&stack, d);
        }
        else
        {
            float val1 = pop(&stack);
            float val2 = pop(&stack);

            switch (ch)
            {
            case '+':
                push(&stack, val2 + val1);
                break;
            case '-':
                push(&stack, val2 - val1);
                break;
            case '*':
                push(&stack, val2 * val1);
                break;
            case '/':
                push(&stack, val2 / val1);
                break;
            }
        }
    }

    return pop(&stack);
}

int main()
{
    char postfix[] = "ab+cd-*ab/";
    float a, b, c, d;

    printf("Enter value for a: ");
    scanf("%f", &a);
    printf("Enter value for b: ");
    scanf("%f", &b);
    printf("Enter value for c: ");
    scanf("%f", &c);
    printf("Enter value for d: ");
    scanf("%f", &d);

    float result = evaluatePostfix(postfix, a, b, c, d);
    printf("The result of the postfix expression is: %.2f\n", result);

    return 0;
}
