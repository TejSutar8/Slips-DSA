#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *rear;
} CircularQueue;

void initQueue(CircularQueue *q)
{
    q->rear = NULL;
}

int isEmpty(CircularQueue *q)
{
    return q->rear == NULL;
}

void addQueue(CircularQueue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (isEmpty(q))
    {
        newNode->next = newNode;
        q->rear = newNode;
    }
    else
    {
        newNode->next = q->rear->next;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int deleteQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    Node *temp = q->rear->next;
    int data = temp->data;
    if (q->rear == q->rear->next)
    {
        q->rear = NULL;
    }
    else
    {
        q->rear->next = temp->next;
    }
    free(temp);
    return data;
}

void displayQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = q->rear->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->rear->next);
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
        printf("2. Delete from Queue\n");
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
            data = deleteQueue(&q);
            if (data != -1)
                printf("Deleted element: %d\n", data);
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
