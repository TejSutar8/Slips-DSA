#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char data[MAX];
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

void push(Stack *s, char c)
{
    if (isFull(s))
    {
        printf("Stack is full.\n");
        return;
    }
    s->data[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

int isPalindrome(char *str)
{
    Stack s;
    initStack(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] != pop(&s))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
