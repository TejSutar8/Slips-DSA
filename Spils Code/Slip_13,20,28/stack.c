#include<stdio.h>
#include"stack.h"

int main()
{
    struct Stack s;
    s.top = -1;  // Initialize stack

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Top element is %d\n", peek(&s));

    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));

    return 0;
}
