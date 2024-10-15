#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertOrdered(Node **head, int data, int ascending)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *current = *head;
    if (ascending)
    {
        while (current != NULL && current->data < data)
        {
            current = current->next;
        }
    }
    else
    {
        while (current != NULL && current->data > data)
        {
            current = current->next;
        }
    }

    if (current == NULL)
    {
        Node *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
    else if (current == *head)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev != NULL)
        {
            current->prev->next = newNode;
        }
        current->prev = newNode;
    }
}

Node *search(Node *head, int data)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int choice, data, order;

    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &order);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertOrdered(&head, data, order);
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%d", &data);
            Node *result = search(head, data);
            if (result != NULL)
            {
                printf("Element %d found in the list.\n", data);
            }
            else
            {
                printf("Element %d not found in the list.\n", data);
            }
            break;
        case 3:
            displayList(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
