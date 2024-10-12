#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Initialize queue
void init()
{
    front = rear = NULL;
}

// Check if the queue is empty
int isempty()
{
    return front == NULL;
}

// Enqueue operation
void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue()
{
    if (isempty())
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    int val = temp->data;
    free(temp);
    return val;
}

// Peek operation
int peek()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

// Display queue
void display()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    return 0;
}
