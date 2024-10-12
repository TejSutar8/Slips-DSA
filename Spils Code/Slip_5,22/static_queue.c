#include <stdio.h>
#include "static_queue.h"

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Peek : %d\n", peek());

    dequeue();
    display();

    printf("Peek : %d\n", peek());
    dequeue();
    display();

    return 0;
}