#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

// Push operation
void push(int val)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

// Pop operation
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
        return stack[top--];
}

// Display stack
void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d -> ", stack[i]);
        printf("NULL\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}
