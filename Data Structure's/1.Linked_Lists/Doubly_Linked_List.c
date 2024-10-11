// Doubly Linked List (Basic Operations: Create, Display)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void append(struct Node **head_ref, int data)
{
    struct Node *new_node = createNode(data);
    struct Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void display(struct Node *node)
{
    struct Node *last;
    printf("Traversal in forward direction:\n");
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("Traversal in reverse direction:\n");
    while (last != NULL)
    {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    display(head);

    return 0;
}
