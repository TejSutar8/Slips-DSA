#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int priority[MAX];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *pq)
{
    pq->size = 0;
}

void addElement(PriorityQueue *pq, int data, int priority)
{
    if (pq->size == MAX)
    {
        printf("Queue is full.\n");
        return;
    }
    int i = pq->size - 1;
    while (i >= 0 && pq->priority[i] > priority)
    {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    pq->data[i + 1] = data;
    pq->priority[i + 1] = priority;
    pq->size++;
}

int deleteElement(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = pq->data;
    for (int i = 0; i < pq->size - 1; i++)
    {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return data;
}

void displayQueue(PriorityQueue *pq)
{
    for (int i = 0; i < pq->size; i++)
    {
        printf("Data: %d, Priority: %d\n", pq->data[i], pq->priority[i]);
    }
}

int main()
{
    PriorityQueue pq;
    initQueue(&pq);
    int choice, data, priority;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            addElement(&pq, data, priority);
            break;
        case 2:
            data = deleteElement(&pq);
            if (data != -1)
                printf("Deleted element: %d\n", data);
            break;
        case 3:
            displayQueue(&pq);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
