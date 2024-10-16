#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int priorities[MAX];
    int front, rear;
} PriorityQueue;

void init(PriorityQueue *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

int isFull(PriorityQueue *pq)
{
    return pq->rear == MAX - 1;
}

int isEmpty(PriorityQueue *pq)
{
    return pq->front == -1 || pq->front > pq->rear;
}

void insert(PriorityQueue *pq, int value, int priority)
{
    if (isFull(pq))
    {
        printf("Priority Queue overflow\n");
        return;
    }
    if (pq->front == -1)
    {
        pq->front = 0;
    }
    pq->rear++;
    pq->items[pq->rear] = value;
    pq->priorities[pq->rear] = priority;
}

int delete(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue underflow\n");
        return -1;
    }
    int highestPriority = pq->priorities[pq->front];
    int pos = pq->front;
    for (int i = pq->front + 1; i <= pq->rear; i++)
    {
        if (pq->priorities[i] > highestPriority)
        {
            highestPriority = pq->priorities[i];
            pos = i;
        }
    }
    int value = pq->items[pos];
    for (int i = pos; i < pq->rear; i++)
    {
        pq->items[i] = pq->items[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }
    pq->rear--;
    if (pq->rear < pq->front)
    {
        pq->front = pq->rear = -1;
    }
    return value;
}

void display(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty\n");
        return;
    }
    for (int i = pq->front; i <= pq->rear; i++)
    {
        printf("Value: %d, Priority: %d\n", pq->items[i], pq->priorities[i]);
    }
}

int main()
{
    PriorityQueue pq;
    init(&pq);
    int choice, value, priority;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter priority: ");
            scanf("%d", &priority);
            insert(&pq, value, priority);
            break;
        case 2:
            value = delete (&pq);
            if (value != -1)
            {
                printf("Deleted value: %d\n", value);
            }
            break;
        case 3:
            display(&pq);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
