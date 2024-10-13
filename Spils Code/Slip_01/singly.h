#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int data)
{
    struct Node *new_node = create(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct Node *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("NULL \n");
}