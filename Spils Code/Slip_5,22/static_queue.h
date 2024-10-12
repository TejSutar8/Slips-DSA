#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void init()
{
    front = -1;
    rear = -1;
}

void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Overflow \n");
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is underflow \n");
        return -1;
    }
    else
    {
        return queue[front++];
    }
}

int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        for (int i = front; i < rear; i++)
        {
            printf("%d ->", queue[i]);
        }
        printf("NULL");
    }
}