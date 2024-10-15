#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *q)
{
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isFull(Deque *q)
{
    return q->size == MAX;
}

int isEmpty(Deque *q)
{
    return q->size == 0;
}

void addFront(Deque *q, int value)
{
    if (isFull(q))
    {
        printf("Deque is full.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->front = (q->front - 1 + MAX) % MAX;
    }
    q->data[q->front] = value;
    q->size++;
}

int getRear(Deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque is empty.\n");
        return -1;
    }
    return q->data[q->rear];
}

void deleteRear(Deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque is empty.\n");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->rear = (q->rear - 1 + MAX) % MAX;
    }
    q->size--;
}

void displayDeque(Deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque is empty.\n");
        return;
    }
    int i = q->front;
    while (1)
    {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Deque q;
    initDeque(&q);
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add to Front\n");
        printf("2. Get Rear\n");
        printf("3. Delete Rear\n");
        printf("4. Display Deque\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            addFront(&q, data);
            break;
        case 2:
            data = getRear(&q);
            if (data != -1)
                printf("Rear element: %d\n", data);
            break;
        case 3:
            deleteRear(&q);
            break;
        case 4:
            displayDeque(&q);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
