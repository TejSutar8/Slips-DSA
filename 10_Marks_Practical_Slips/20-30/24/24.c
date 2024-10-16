#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int front, rear;
} CircularQueue;

void init(CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q)
{
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue *q)
{
    return q->front == -1;
}

void AddQueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int peek(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    return q->items[q->front];
}

void display(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[i]);
}

int main()
{
    CircularQueue q;
    init(&q);
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add to Queue\n");
        printf("2. Peek\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to add: ");
            scanf("%d", &value);
            AddQueue(&q, value);
            break;
        case 2:
            value = peek(&q);
            if (value != -1)
            {
                printf("Front element: %d\n", value);
            }
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
