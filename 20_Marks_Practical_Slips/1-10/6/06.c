#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

QueueNode *createQueueNode(int data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int data)
{
    QueueNode *newNode = createQueueNode(data);
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

int peek(Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->front->data;
}

void displayQueue(Queue *q)
{
    QueueNode *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Peek\n");
        printf("5. Check if Queue is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
            data = dequeue(&q);
            if (data == -1)
                printf("Queue is empty.\n");
            else
                printf("Dequeued: %d\n", data);
            break;
        case 3:
            printf("Queue: ");
            displayQueue(&q);
            break;
        case 4:
            data = peek(&q);
            if (data == -1)
                printf("Queue is empty.\n");
            else
                printf("Front element: %d\n", data);
            break;
        case 5:
            if (isEmpty(&q))
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
