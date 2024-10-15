#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} CircularQueue;

void initQueue(CircularQueue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(CircularQueue *q)
{
    return q->front == NULL;
}

void addQueue(CircularQueue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (isEmpty(q))
    {
        newNode->next = newNode;
        q->front = q->rear = newNode;
    }
    else
    {
        newNode->next = q->rear->next;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int peek(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

void displayQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = q->front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main()
{
    CircularQueue q;
    initQueue(&q);
    int choice, data;

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
            printf("Enter data: ");
            scanf("%d", &data);
            addQueue(&q, data);
            break;
        case 2:
            data = peek(&q);
            if (data != -1)
                printf("Front element: %d\n", data);
            break;
        case 3:
            displayQueue(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
