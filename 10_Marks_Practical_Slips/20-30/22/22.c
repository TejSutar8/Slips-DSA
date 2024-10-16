#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}

void AddQueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
}

int DeleteQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    return q->items[(q->front)++];
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    init(&q);
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add to Queue\n");
        printf("2. Delete from Queue\n");
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
            value = DeleteQueue(&q);
            if (value != -1)
            {
                printf("Deleted value: %d\n", value);
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
