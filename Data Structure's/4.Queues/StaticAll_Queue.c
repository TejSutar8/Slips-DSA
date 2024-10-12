#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

// Initialize queue
void init()
{
    front = -1;
    rear = -1;
}

// Enqueue operation
void enqueue(int val)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

// Dequeue operation
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
        return queue[front++];
}

// Peek operation
int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
        return queue[front];
}

// Display queue
void display()
{
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d -> ", queue[i]);
        printf("NULL\n");
    }
}

int main()
{
    init(); // Initialize the queue

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Peek: %d\n", peek());

    dequeue();
    display();

    printf("Peek: %d\n", peek());
    dequeue();
    display();

    return 0;
}
