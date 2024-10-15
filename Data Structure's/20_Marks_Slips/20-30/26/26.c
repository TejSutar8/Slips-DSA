#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data, int ascending)
{
    Node *newNode = createNode(data);
    if (*head == NULL || (ascending && (*head)->data >= data) || (!ascending && (*head)->data <= data))
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && ((ascending && current->next->data < data) || (!ascending && current->next->data > data)))
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node *search(Node *head, int data, int ascending)
{
    Node *current = head;
    while (current != NULL && ((ascending && current->data < data) || (!ascending && current->data > data)))
    {
        current = current->next;
    }
    if (current != NULL && current->data == data)
    {
        return current;
    }
    return NULL;
}

void display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    int choice, data, order;

    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &order);

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(&head, data, order);
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%d", &data);
            Node *result = search(head, data, order);
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
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
